#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int main(){
//	int i = 0;
//
//	return 0;
//}



//输入的数列可以分为多少段有序序列
//void count(int arr[],int n){
//	int m = 1,con=0;
//	while (m < n){
//		if (arr[m]>arr[m - 1]){
//			if (arr[m + 1] <= arr[m]){
//				con++;
//				m++;
//			}
//		}
//		if (arr[m] < arr[m-1]){
//			if (arr[m + 1] >= arr[m]){
//				con++;
//				m++;
//			}
//		}
//		if (arr[m] == arr[m - 1]){
//			if (arr[m + 1] >= arr[m]){
//				con++;
//				m++;
//			}
//		}
//		m++;
//	}
//	if (n == 1){
//		con++;
//	}
//	cout << con << endl;
//}
//int main(){
//	int arr[100000];
//	int n,i;
//	cin >> n;
//	if (n >= 1 && n <= 100000){
//		for (i = 0; i < n; i++){
//			cin >> arr[i];
//		}
//		count(arr, n);
//	}
//	return 0;
//}