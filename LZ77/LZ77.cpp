#include "LZ77.h"
#include <iostream>
using namespace std;

#include <assert.h>


LZ77::LZ77()
: _pWin(new UCH[WSIZE * 2])
, _ht(WSIZE)
{}

LZ77::~LZ77()
{
	delete[] _pWin;
	_pWin = nullptr;
}


void LZ77::CompressFile(const std::string& strFilePath)
{
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	// ��ȡ�ļ���С
	fseek(fIn, 0, SEEK_END);
	ULL fileSize = ftell(fIn);

	// ���Դ�ļ��Ĵ�СС��MIN_MATCH���򲻽��д���
	if (fileSize <= MIN_MATCH)
	{
		cout << "�ļ�̫С����ѹ��" << endl;
		return;
	}

	// ��ѹ���ļ��ж�ȡһ�������������ݵ�������
	fseek(fIn, 0, SEEK_SET);
	USH lookAhead = fread(_pWin, 1, 2 * WSIZE, fIn);
	
	USH hashAddr = 0;
	// abcdefg....������ʼhashAddr
	for (USH i = 0; i < MIN_MATCH - 1; ++i)
		_ht.HashFunc(hashAddr, _pWin[i]);


	// ѹ����
	FILE* fOUT = fopen("2.lzp", "wr");
	assert(fOUT);

	USH start = 0;
	USH matchHead = 0;
	UCH curMatchLength = 0;
	USH curMatchDist = 0;

	// lookAhead��ʾ���л�������ʣ���ֽڵĸ���
	while (lookAhead)
	{
		// 1. ����ǰ�����ַ����뵽��ϣ���У�����ȡƥ������ͷ
		// 2. ��֤�ڲ��һ��������Ƿ��ҵ�ƥ��,�����ƥ�䣬���ƥ��
		// 3. ��֤�Ƿ��ҵ�ƥ��
		if (curMatchLength < MIN_MATCH)
		{
			// �ڲ��һ�������δ�ҵ��ظ��ַ���
			// ��startλ�õ��ַ�д�뵽ѹ���ļ���
		}
		else
		{
			// �ҵ�ƥ��
			// ��<����, ����>��д�뵽ѹ���ļ���
			// д����
			// �������л�������ʣ����ֽ���
			// ���Ѿ�ƥ����ַ�����������һ�齫����뵽��ϣ����

		}
	}
}

UCH LZ77::LongestMatch(USH matchHead, USH& MatchDist)
{
	return 0;
}