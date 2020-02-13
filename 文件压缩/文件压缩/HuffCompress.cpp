#define _CRT_SECURE_NO_WARNINGS 1
#include "HuffCompress.h"
#include <assert.h>
#include "Hftree.hpp"

HuffCompress::HuffCompress(){
	Cinfo.resize(256);
	for (int i = 0; i < 256; i++){   //��ʼ���ַ���Ϣ
		Cinfo[i].ch = i;
		Cinfo[i].count = 0;
	}
}

void HuffCompress::CompressFile(const string& path){
	                        ///////////////////////////1.ͳ��ԭ�ļ���ÿ���ַ����ֵĴ���/////////////////////////////////////
	FILE* FileIn = fopen(path.c_str(), "r");  // r ��ʾ����ֻ����ʽ��
	if (nullptr == FileIn){   //�ж��ļ����Ƿ�ɹ�
		assert(false);
		return;
	}

	unsigned char* pReadBuff = new unsigned char[1024];  //pReadBuff�����洢���������ݣ�һ��1024�ֽڣ�1K��
	int readsize = 0;
	while (true){
		readsize = fread(pReadBuff, 1, 1024, FileIn);  
		//fread�����������������ݱ��浽 pReadBuff �У�һ��Ԫ��ռһ���ֽڣ�һ�ζ�1024�ֽڣ���FileIn�ж�ȡ
		//����ֵΪ�����˶����ֽ�
		if (0 == readsize){  //��ʾ�Ѿ���ȡ����
			break;
		}
		for (int i = 0; i < readsize; ++i){
			Cinfo[pReadBuff[i]].count++;
		}
	}
	 
	                 ////////////////////////////2.���ַ����ֵĴ���ΪȨֵ������������/////////////////////////////////////

	HfTree<Charinfo> tree(Cinfo,Charinfo(0));

	                   ////////////////////////////////////3.��ȡÿ���ַ��ı���/////////////////////////////////////////

	HuffCompress::GetCharCode(tree.GetRoot());

	                   /////////////////////////////////////4.���ַ�������дԭ�ļ�/////////////////////////////////////

	FILE* FileOut = fopen("t2.txt", "w");   //��(����)һ���ļ������洢ѹ�����ļ���  w -�� ��д��ʽ��
	
	if (nullptr == FileOut){       //�򿪣�������ʧ��
		assert(false);
		return;
	}
	
	Compresskey(FileOut, path);  //��д��ѹ���ļ���Ϣ����ѹ��ʱʹ��

	fseek(FileIn, 0, SEEK_SET);    //SEEK_END��ʾ�ļ�ĩβ
	char rs = 0;  //������д
	int sum = 0;  //�����������Ƿ������һ���ֽ�

	while (true){         //�ٴζ�ȡ�ļ���������д

		//�˴����ֵ����⣺��֮ǰ�����ַ����ִ�����ʱ���Ѿ�����һ���ļ��������ļ�ָ��ָ�����ĩβ�����ǲ���ָ��ָ��ͷ���ٴζ��Ƕ��������ݵ�
		//���Ծ���������� fseek()  ����
		 
		readsize = fread(pReadBuff, 1, 1024, FileIn);
		if (0 == readsize){   //��ȡ����������ͬʱѹ��������
			break;
		}
		//�����ַ��ı�����ļ�������д
		for (size_t i = 0; i < readsize; ++i){
			string Code = Cinfo[pReadBuff[i]].code;
			for (size_t j = 0; j < Code.size(); ++j){
				rs <<= 1;   //��һ��ѭ����ȫ0������һλ��Ӱ��
				if ('1' == Code[j]){
					rs |= 1;     //��λ���ձ�����д   |=  ��λ���
				}
				sum++;
				if (8 == sum){              //д��һ���ֽ�
					fputc(rs, FileOut);    //fputc ���ļ���д�뵥���ֽ�
					rs = 0;           
					sum = 0;
				}
			}

		}

	}
	//����ֺ�һ���ֽ�û�з����Ĵ���,�������Ƶ���λ����λȫ0�������������ѹ��
	if (sum < 8){
		rs <<= (8 - sum);
		fputc(rs, FileOut);
	}

	delete[] pReadBuff;  //�ͷ�����Ŀռ�
	fclose(FileIn);   //�ر��ļ� 
	fclose(FileOut);
}

//  t2.txt
string HuffCompress::GetFileType(const string filename){    //ȡ���ļ���׺

	return filename.substr(filename.rfind('.'));  //substr()��ȡ�ַ������ζ�����Ĭ�Ͻ�ȡ��ĩβ���Ӻ���ǰ������.��������λ��
}

void HuffCompress::Compresskey(FILE* FileOut, const string& filename){    //д��ѹ���ļ���Ϣ
	assert(FileOut);
	string filekey;  //����Ҫд����ļ���Ϣ

	//�ļ����ͣ���׺��
	filekey += GetFileType(filename);
	filekey += '\n';

	//ͳ����Ϣ�������ַ���Ϣ

	size_t num = 0;  //��Ϣ����
	string strkey;   //�ַ���Ϣ���ַ������ִ�����   
	char arr[64] = {0};       //��������װ�����ִ��������� int-��char  �������СӦ�ô��ڳ��ֲ�ͬ�ַ�����

	for (int i = 0; i < 256; ++i){
		if (0 != Cinfo[i].count){
			num++;
			strkey += Cinfo[i].ch; 
			strkey += '-';            //�ָ�
			_itoa(Cinfo[i].count, arr, 10);  // ��һ ���� �ζ� ת��Ϊ 10 ����
			strkey += arr;
			strkey += '\n';     //һ���ַ���ϢΪһ��
		}
	}

	//��Ϣ����
	_itoa(num, arr, 10);
	filekey += arr;
	filekey += '\n';
	//�ַ���Ϣ
	filekey += strkey;

	//���ս�������Ϣд��
	fwrite(filekey.c_str(), 1, filekey.size(), FileOut); //�����ֱ�Ϊ д������ һ��Ԫ�ش�С д����� Ҫд���Ŀ��

}


  
void HuffCompress::GetCharCode(HfNode<Charinfo>* pRoot){    //�����ȡ
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
		while (parent){                   //���¶��ϵĻ�ȡ����
			if (parent->pLeft == cur){
				code += '0';
			}
			else{
				code += '1';
			}
			cur = parent;
			parent = cur->pParent;
		}
		reverse(begin(code), end(code));  //��ת����
		Cinfo[pRoot->_W.ch].code = code;     //�洢����
	}
}

void HuffCompress::UNCopressFile(const string& path){   //��ѹ��

 	FILE* FileIn = fopen(path.c_str(), "r");    //��ȡ�ļ�
	if (nullptr == FileIn){
		assert(false);
		return;
	}

	/////////////////////////////////1.��ȡѹ����Ϣ//////////////////////////////////
	 
	//�ļ���׺
	string filetype;   
	ReadLine(FileIn,filetype);

	//�ַ���Ϣ����
	string numLine;  
	int num;
	ReadLine(FileIn, numLine);
	num = atoi(numLine.c_str());

	//�ַ���Ϣ
	for (int i = 0; i < num; ++i){
		string Cline;
		ReadLine(FileIn, Cline);
		//������� ��\n�� ���ȱ����ַ����Ҷ��һ��
		if (Cline.empty()){
			Cline += '\n';
			ReadLine(FileIn, Cline);
		}

	//A-1
		Cinfo[(unsigned char)Cline[0]].count = atoi(Cline.c_str() + 2);   //�ַ���Ϣһ��3���ַ�����һ��Ϊ�ַ���������Ϊ���ִ���
	}

	/////////////////////////////////2.��ԭ��������//////////////////////////////////

	HfTree<Charinfo> tree;
	tree.createHfTree(Cinfo, Charinfo(0)); 
	 
	/////////////////////////////////3.��ѹ��////////////////////////////

	FILE* FileOut = fopen("t3.txt", "w");
	assert(FileOut);

	size_t readsize;
	unsigned char* pReadBuff = new unsigned char[1024];
	unsigned char rs = 0;
	HfNode<Charinfo>* cur=tree.GetRoot();  //�Ӹ��ڵ㿪ʼ�����ձ������
	size_t filesize = cur->_W.count;   //�Ӹ��ڵ���õ�ԭ�ļ���С
	size_t unsize = 0;

	while (true){
		readsize=fread(pReadBuff,1,1024,FileIn);
		if (0 == readsize){
			break;
		}
		for (size_t i = 0; i < readsize; ++i){
			rs = pReadBuff[i];
			//ÿ�δ���һ���ֽ� 8 ������λ
			for (int j = 0; j < 8; ++j){
				if (rs & 0x80){          //�� 8λ �ֽ��жϣ���һ�ζ�������λ��0x80 Ϊ 1000 0000 
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
					cur = tree.GetRoot();   //���һ������Ľ�ѹ�������ع���ڵ�
				}
			}
		}
	}
	delete[] pReadBuff;
	fclose(FileIn);
	fclose(FileOut);
}

void HuffCompress::ReadLine(FILE* FileIn, string& str){   //��ȡһ���ļ�����
	assert(FileIn);

	while (!feof(FileIn)){        //feof() �ж��ļ�ָ���Ƿ����ļ�ĩβ  
		char rs = fgetc(FileIn);     //fgetc() ���ļ��ж�ȡһ���ַ�
		if (rs == '\n'){
			break;
		}
		str += rs;
	}
}
