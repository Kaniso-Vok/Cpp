//#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//二进制插入
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		return n ^ (m << j);
//	}
//};


//bool find(int n){
//	for (int i = 1; i < n; ++i){
//		if (0 == n%i&&i != 1){
//			return false;
//		}
//	}
//	return true;
//}
//void func(int n){
//	int re, res = 100000, a, b;
//	for (int i = 1; i < n; i++){
//		if (find(i)){
//			for (int j = i; j < n; j++){
//				if (find(j) && (i + j) == n){
//					re = j - i;
//					if (re<res){
//						res = re;
//						a = i;
//						b = j;
//					}
//				}
//			}
//		}
//	}
//	cout << a << endl;
//	cout << b << endl;
//}
//int main(){
//	int  n;
//	while (cin >> n){
//		func(n);
//	}
//	return 0;
//}