#pragma once
#include "Hftree.hpp"
#include <string>
#include <vector>
using namespace std;

struct Charinfo{       //�ַ���Ϣ
	unsigned char ch;          //���е��޷��Ŷ���Ϊ�˺����ַ�׼���ģ���Ȼ�Ļ�����ֵ�п���Ϊ����
	size_t count;   //���ִ���
	string code;   //���ձ���

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
	void Compresskey(FILE* FileOut, const string& filename);   //��ѹ���ļ�ʱд���ļ����͡���Ϣ�������ַ����ִ�������Ϣ����ѹ��ʱʹ��
	string GetFileType(const string filename);        //ͨ���ļ�����ȡ�ļ����ͣ���׺��,д��ѹ����Ϣʱʹ��
	void ReadLine(FILE* FileIn, string& str);   //��ȡһ��ѹ���ļ���Ϣ����ѹ��ʱʹ��

private:
	vector<Charinfo> Cinfo;
};