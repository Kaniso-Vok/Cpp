#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//int main(){
//	int n, mmax = -1e10, max = 0;
//	cin >> n;
//	int arr[100000];
//	for (int i = 0; i < n; ++i){
//		cin >> arr[i];
//	}
//	int m = 0;
//	while (m<n){
//		max += arr[m];
//		if (max>mmax){
//			mmax = max;
//		}
//		if (max < 0 && m != (n - 1)){
//			max = 0;
//		}
//		m++;
//	}
//	cout << mmax;
//	return 0;
//}

//bool check(string s){
//	int i = 0;
//	int len = s.length();
//	while (i < len){
//		if (s[i] != s[len-1]){
//			return false;
//		}
//		i++;
//		len--;
//	}
//	return true;
//}
//
//int main(){
//	string s1, s2, ss;
//	cin >> s1 >> s2;
//	int i = 0, len = s1.length() + 1, sum = 0;
//	ss = s1;
//	while (i<len){
//		s1 = ss;
//		s1.insert(i, s2);
//		if (check(s1)){
//			sum++;
//		}
//		i++;
//	}
//	cout << sum;
//	return 0;
//}