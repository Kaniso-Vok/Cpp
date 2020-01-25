#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

//int evalRPN(vector<string>& tokens) {
//	stack<int> vec;
//	for (string e : tokens){
//		if (isdigit(e[e.size()-1])){
//			vec.push(stoi(e));
//		}
//		else{
//			int a, b;
//			a = vec.top();
//			vec.pop();
//			b = vec.top();
//			vec.pop();
//			if (e == "+"){
//				vec.push(b + a);
//			}
//			else if (e == "-"){
//				vec.push(b - a);
//			}
//			else if (e == "*"){
//				vec.push(b * a);
//			}
//			else if (e == "/"){
//				vec.push(b / a);
//			}
//		}
//	}
//	return vec.top();
//}
//
//int main(){
//	vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
//	evalRPN(tokens);
//	return 0;
//}


//int findUnsortedSubarray(vector<int>& nums) {
//	vector<int>w = nums;
//	sort(begin(w), end(w));
//	int i = 0, j = w.size()-1;
//	for (int v : w){
//		if (v != nums[i]){
//			break;
//		}
//		i++;
//	}
//	if (i-1 == j){
//		return 0;
//	}
//	for (; j > 0; j--){
//		if (w[j] != nums[j]){
//			break;
//		}
//	}
//	return j-i+1;
//}
//
//int main(){
//	vector<int> w = { 1,2,3,4 };
//	findUnsortedSubarray(w);
//	return 0;
//}
