#define _CRT_SECURE_NO_WARNINGS 1
#include "HuffCompress.h"
#include <assert.h>
#include "Hftree.hpp"

HuffCompress::HuffCompress(){
	Cinfo.resize(256);
	for (int i = 0; i < 256; i++){   //初始化字符信息
		Cinfo[i].ch = i;
		Cinfo[i].count = 0;
	}
}

void HuffCompress::CompressFile(const string& path){
	                        
	FILE* FileIn = fopen(path.c_str(), "rb");  // r 表示按照只读方式打开
	if (nullptr == FileIn){   //判断文件打开是否成功
		assert(false);
		return;
	}

	///////////////////////////1.统计原文件中每个字符出现的次数/////////////////////////////////////
	unsigned char* pReadBuff = new unsigned char[1024];  //pReadBuff用来存储读到的内容，一次1024字节（1K）
	int readsize = 0;
	while (true){
		readsize = fread(pReadBuff, 1, 1024, FileIn);  
		//fread读操作，将读到内容保存到 pReadBuff 中，一个元素占一个字节，一次读1024字节，从FileIn中读取
		//返回值为读到了多少字节
		if (0 == readsize){  //表示已经读取结束
			break;
		}
		for (int i = 0; i < readsize; ++i){
			Cinfo[pReadBuff[i]].count++;
		}
	}
	 
	                 ////////////////////////////2.以字符出现的次数为权值创建哈夫曼树/////////////////////////////////////

	HfTree<Charinfo> tree(Cinfo,Charinfo(0));

	                   ////////////////////////////////////3.获取每个字符的编码/////////////////////////////////////////

	HuffCompress::GetCharCode(tree.GetRoot());

	                   /////////////////////////////////////4.用字符编码重写原文件/////////////////////////////////////

	FILE* FileOut = fopen("t2.txt", "wb");   //打开(创建)一个文件用来存储压缩后文件，  w -》 以写方式打开
	
	if (nullptr == FileOut){       //打开（创建）失败
		assert(false);
		return;
	}
	
	Compresskey(FileOut, path);  //先写入压缩文件信息，解压缩时使用

	fseek(FileIn, 0, SEEK_SET);    //SEEK_END表示文件末尾
	char rs = 0;  //用来重写
	int sum = 0;  //用来计数，是否放满了一个字节

	while (true){         //再次读取文件，进行重写

		//此处出现的问题：在之前计算字符出现次数的时候已经读过一次文件，所以文件指针指向的是末尾，若是不将指针指向开头，再次读是读不到内容的
		//所以就有了上面的 fseek()  操作
		 
		readsize = fread(pReadBuff, 1, 1024, FileIn);
		if (0 == readsize){   //读取结束条件（同时压缩结束）
			break;
		}
		//根据字符的编码对文件进行重写
		for (size_t i = 0; i < readsize; ++i){
			string Code = Cinfo[pReadBuff[i]].code;
			for (size_t j = 0; j < Code.size(); ++j){
				rs <<= 1;   //第一次循环是全0，左移一位无影响
				if ('1' == Code[j]){
					rs |= 1;     //按位依照编码重写   |=  按位或等
				}
				sum++;
				if (8 == sum){              //写满一个字节
					fputc(rs, FileOut);    //fputc 在文件中写入单个字节
					rs = 0;           
					sum = 0;
				}
			}

		}

	}
	//如果字后一个字节没有放满的处理,有数据推到高位，低位全0，这样处理方便解压缩
	if (sum < 8){
		rs <<= (8 - sum);
		fputc(rs, FileOut);
	}

	delete[] pReadBuff;  //释放申请的空间
	fclose(FileIn);   //关闭文件 
	fclose(FileOut);
}

//  t2.txt
string HuffCompress::GetFileType(const string filename){    //取得文件后缀

	return filename.substr(filename.rfind('.'));  //substr()截取字符串，参二不传默认截取到末尾，从后往前搜索‘.’返回其位置
}

void HuffCompress::Compresskey(FILE* FileOut, const string& filename){    //写入压缩文件信息
	assert(FileOut);
	string filekey;  //最终要写入的文件信息

	//文件类型（后缀）
	filekey += GetFileType(filename);
	filekey += '\n';

	//统计信息行数和字符信息

	size_t num = 0;  //信息行数
	string strkey;   //字符信息（字符及出现次数）   
	char arr[64] = {0};       //用来接收装换出现次数的类型 int-》char  ，数组大小应该大于出现不同字符个数

	for (int i = 0; i < 256; ++i){
		if (0 != Cinfo[i].count){
			num++;
			strkey += Cinfo[i].ch; 
			strkey += '-';            //分隔
			_itoa(Cinfo[i].count, arr, 10);  // 参一 放入 参二 转换为 10 进制
			strkey += arr;
			strkey += '\n';     //一个字符信息为一行
		}
	}

	//信息行数
	_itoa(num, arr, 10);
	filekey += arr;
	filekey += '\n';
	//字符信息
	filekey += strkey;

	//最终将所有信息写入
	fwrite(filekey.c_str(), 1, filekey.size(), FileOut); //参数分别为 写入内容 一个元素大小 写入个数 要写入的目标

}


  
void HuffCompress::GetCharCode(HfNode<Charinfo>* pRoot){    //编码获取
	typedef HfNode<Charinfo> node;
	if (nullptr == pRoot){
		return;
	}
	string code;
	GetCharCode(pRoot->pLeft);
	GetCharCode(pRoot->pRight);
	
	if (nullptr == pRoot->pLeft && nullptr == pRoot->pRight){
		node* cur = pRoot;
		node* parent = cur->pParent;
		while (parent){                   //自下而上的获取编码
			if (parent->pLeft == cur){
				code += '0';
			}
			else{
				code += '1';
			}
			cur = parent;
			parent = cur->pParent;
		}
		reverse(begin(code), end(code));  //翻转编码
		Cinfo[pRoot->_W.ch].code = code;     //存储编码
	}
}

void HuffCompress::UNCopressFile(const string& path){   //解压缩

 	FILE* FileIn = fopen(path.c_str(), "rb");    //读取文件
	if (nullptr == FileIn){
		assert(false);
		return;
	}

	/////////////////////////////////1.获取压缩信息//////////////////////////////////
	 
	//文件后缀
	string filetype;   
	ReadLine(FileIn,filetype);

	//字符信息行数
	string numLine;  
	int num;
	ReadLine(FileIn, numLine);
	num = atoi(numLine.c_str());

	//字符信息
	for (int i = 0; i < num; ++i){
		string Cline;
		ReadLine(FileIn, Cline);
		//如果读到 ‘\n’ 就先保存字符并且多读一行
		if (Cline.empty()){
			Cline += '\n';
			ReadLine(FileIn, Cline);
		}

	//A-1
		Cinfo[(unsigned char)Cline[0]].count = atoi(Cline.c_str() + 2);   //字符信息一行3个字符，第一个为字符，第三个为出现次数
	}

	/////////////////////////////////2.还原哈夫曼树//////////////////////////////////

	HfTree<Charinfo> tree;
	tree.createHfTree(Cinfo, Charinfo(0)); 
	 
	/////////////////////////////////3.解压缩////////////////////////////

	FILE* FileOut = fopen("t3.txt", "wb");
	assert(FileOut);

	size_t readsize;
	unsigned char* pReadBuff = new unsigned char[1024];
	unsigned char rs = 0;
	HfNode<Charinfo>* cur=tree.GetRoot();  //从根节点开始，按照编码解锁
	size_t filesize = cur->_W.count;   //从根节点的拿到原文件大小
	size_t unsize = 0;

	while (true){
		readsize=fread(pReadBuff,1,1024,FileIn);
		if (0 == readsize){
			break;
		}
		for (size_t i = 0; i < readsize; ++i){
			rs = pReadBuff[i];
			//每次处理一个字节 8 个比特位
			for (int j = 0; j < 8; ++j){
				if (rs & 0x80){          //按 8位 字节判断，诶一次都检测最高位，0x80 为 1000 0000 
					cur = cur->pRight;
				}
				else{
					cur = cur->pLeft;
				}
				rs <<= 1;
				if (nullptr == cur->pLeft&&nullptr == cur->pRight){
					unsize++;
					fputc(cur->_W.ch, FileOut);
					if (unsize == filesize){
						break;
					}
					cur = tree.GetRoot();   //完成一个编码的解压缩后将起点回归根节点
				}
			}
		}
	}
	delete[] pReadBuff;
	fclose(FileIn);
	fclose(FileOut);
}

void HuffCompress::ReadLine(FILE* FileIn, string& str){   //读取一行文件数据
	assert(FileIn);

	while (!feof(FileIn)){        //feof() 判断文件指针是否到了文件末尾  
		char rs = fgetc(FileIn);     //fgetc() 从文件中读取一个字符
		if (rs == '\n'){
			break;
		}
		str += rs;
	}
}
