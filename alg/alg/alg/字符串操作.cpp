#define _CRT_SECURE_NO_WARNINGS 1
//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过
//替换之后的字符串为We%20Are % 20Happy。
//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		char* t = str;
//		int sum = 0;
//		while (*t){
//			if (*t == ' '){
//				sum++;
//			}
//			t++;
//		}
//		char* ostr = str + length;
//		char* nstr = str + length + (sum * 2);
//		while (ostr >= str&&nstr >= str){
//			if (*ostr == ' '){
//				*nstr-- = '0';
//				*nstr-- = '2';
//				*nstr-- = '%';
//			}
//			else{
//				*nstr-- = *ostr;
//			}
//			ostr--;
//		}
//	}
//};