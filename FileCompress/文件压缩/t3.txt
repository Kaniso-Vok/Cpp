#pragma once
#include "Hftree.hpp"
#include <string>
#include <vector>
using namespace std;

struct Charinfo{       //字符信息
	unsigned char ch;          //所有的无符号都是为了汉字字符准备的，不然的话符号值有可能为负数
	size_t count;   //出现次数
	string code;   //最终编码

	Charinfo(size_t _count = 0) :
		count(_count){}

	Charinfo operator +(const Charinfo& chr)const{
		return Charinfo(count + chr.count);
	}

	bool operator >(const Charinfo& chr)const{
		return count > chr.count;
	}

	bool operator ==(const Charinfo& chr)const{
		return count == chr.count;
	}
};

class HuffCompress{
public:
	HuffCompress();
	void CompressFile(const string& path);
	void UNCopressFile(const string& path);

private:
	void GetCharCode(HfNode<Charinfo>* pRoot);
	void Compresskey(FILE* FileOut, const string& filename);   //在压缩文件时写入文件类型、信息行数、字符出现次数等信息，解压缩时使用
	string GetFileType(const string filename);        //通过文件名获取文件类型（后缀）,写入压缩信息时使用
	void ReadLine(FILE* FileIn, string& str);   //读取一行压缩文件信息，解压缩时使用

private:
	vector<Charinfo> Cinfo;
};