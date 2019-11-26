#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int Sum(int n){
	int i = 1,j=0;
	if (n < 3){
		return i;
	}
		for (int m = 3; m < n; m++){
			i *= 2;
		}
	return i;
}
int main(){
	int n;
	while (cin >> n){
		cout << Sum(n) << endl;
	}
	return 0;
}