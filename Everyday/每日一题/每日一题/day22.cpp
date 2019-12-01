#define _CRT_SECURE_NO_WARNINGS 1
//小易升级
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
//int ab(int a, int b){
//	int temp = 1;
//	do{
//		if (b%a == 0){
//			return a;
//		}
//		else{
//			temp = b%a;
//			b = a;
//			a = temp;
//		}
//	} while (temp != 0);
//	return temp;
//}
//
//int main() {
//	int a, n;
//	while (scanf("%d%d", &n, &a) != EOF) {
//		for (int i = 0; i < n; ++i){
//			int b;
//			scanf("%d", &b);
//			if (a >= b) {
//				a += b;
//			}
//			else {
//				a += ab(a, b);
//			}
//		}
//		printf("%d\n", a);
//	}
//	return 0;
//}

//找出字符串中第一个只出现一次的字符
