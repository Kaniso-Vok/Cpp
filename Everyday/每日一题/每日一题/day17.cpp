#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int fun(int n){
//	int a[50][50] = {0};
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < 2*i + 1; j++){
//			if (i == 0 || j == 0 || j == 2 * i){
//				a[i][j] = 1;
//			}
//			else if (j == 1){
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//			}
//			else{
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j - 2];
//			}
//		}
//	}
//	for (int i = 0; i < ((2*(n-1)+1) / 2); ++i){
//		if (a[n - 1][i] % 2 == 0){
//			return i + 1;
//		}
//	}
//	return -1;
//}
//int main(){
//	int n;
//	while (cin >> n){
//		cout << fun(n) << endl;
//	}
//	return 0;
//}