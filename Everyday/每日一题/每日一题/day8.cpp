#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int main(){
//	int a, b,i=1;
//	cin >> a >> b;
//	for (int i = 1;; i++){
//		if (i%a == 0){
//			if (i%b == 0){
//				cout << i;
//				return 0;
//			}
//		}
//		if (i%b == 0){
//			if (i%a == 0){
//				cout << i;
//				return 0;
//			}
//		}
//	}
//	cout << i;
//	return 0;
//}

//Î´½â¾ö
//#include<string>
//int main(){
//	int n, m = 0;
//	bool res1,res2;
//	string s[100];
//	cin >> n;
//	for (int i = 0; i < n; i++){
//		cin >> s[i];
//	}
//	while (m < n-1){
//		if (s[m+1][0] >= s[m][0]){
//			res1=true;
//		}
//		else{
//			res1 = false;
//			break;
//		}
//		m++;
//	}
//	m = 0;
//	while (m < n-1){
//		if (s[m + 1].length()>=s[m].length()){
//			res2 = true;
//		}
//		else{
//			res2 = false;
//			break;
//		}
//		m++;
//	}
//	if (res1 == true && res2 == false){
//		cout << "lexicographically";
//	}
//	else if (res2 == true && res1 == false){
//		cout << "lengths";
//	}
//	else if (res2 == true && res1 == true){
//		cout << "both";
//	}
//	else{
//		cout << "none";
//	}
//	return 0;
//}