#define _CRT_SECURE_NO_WARNINGS 1
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20�������磬���ַ���ΪWe Are Happy.�򾭹�
//�滻֮����ַ���ΪWe%20Are % 20Happy��
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