#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//查找到最近的斐波那契数的距离
//int main(){
//	int n,a=0,b=1,c;
//	cin >> n;
//	while (b <= n){
//		c = a;
//		a = b;
//		b = a + c;
//	}
//	cout << min(n - a, b - n);
//	return 0;
//}

//括号匹配
//class Parenthesis {
//public:
//	bool chkParenthesis(string str, int n) {
//		int i = 0, res = 0;
//		while (i < n){
//			if (str[i] == '{' || str[i] == '(' || str[i] == '['){
//				res++;
//			}
//			else if (str[i] == '}' || str[i] == ')' || str[i] == ']'){
//				res--;
//			}
//			else{
//				return false;
//			}
//			i++;
//		}
//		if (res != 0){
//			return false;
//		}
//		else{
//			return true;
//		}
//	}
//};