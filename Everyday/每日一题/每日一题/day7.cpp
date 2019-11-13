#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
bool check(char str[],int n){
	int i = 0,res=0;
	while (i < n){
		if (str[i] == '{' || str[i] == '(' || str[i] == '['){
			res++;
		}
		if (str[i] == '}' || str[i] == ')' || str[i] == ']'){
			res--;
		}
		i++;
	}
	if (res != 0){
		return false;
	}
	else{
		return true;
	}
}
int main(){
	int n=1,res=0;
	char str[1000];
	for (int i = 0; getchar()!= '\n'; i++){
		cin >> str[i];
	}
	cin >> n;
	check(str, n);
	return 0;
}