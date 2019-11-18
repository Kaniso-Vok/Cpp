#define _CRT_SECURE_NO_WARNINGS 1
//Î´½â¾ö
//#include<iostream>
//using namespace std;
//bool find(int n){
//	for (int i = 1; i < n; ++i){
//		if (0==n%i&&i!=1){
//			return false;
//		}
//	}
//	return true;
//}
//int main(){
//	int  n,re,res=100000,a,b;
//	cin >> n;
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
//	return 0;
//}