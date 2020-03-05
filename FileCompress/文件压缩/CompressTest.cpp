#define _CRT_SECURE_NO_WARNINGS 1
#include "HuffCompress.h"

int main(){
	HuffCompress Zip;
	Zip.CompressFile("t1.txt");
	Zip.UNCopressFile("t2.txt");
	return 0;
}	