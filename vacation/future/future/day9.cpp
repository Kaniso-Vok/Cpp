#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//string addBinary(string a, string b) {
//	int n = a.size();
//	int m = b.size();
//	while (n < m){
//		a = '0'+a  ;
//		n++;
//	}
//	while (m < n){
//		b = '0'+b ;
//		m++;
//	}
//	for (int i = a.size() - 1; i>0; i--){
//		a[i] = a[i] - '0' + b[i];
//		if (a[i]>'1'){
//			a[i] = (a[i] - '0') % 2 + '0';
//			a[i - 1] = a[i - 1] + '1' - '0';
//		}
//	}
//		a[0] =a[0]-'0'+b[0];
//		if (a[0] > '1'){
//			a[0] = (a[0] - '0') % 2 + '0';
//			a = '1'+a;
//		}
//	return a;
//}
//
//int main(){
//	string a = "101",b="11";
//	addBinary(a, b);
//	return 0;
//}
//vector<int> twoSum(vector<int>& nums, int target) {
//	vector<int> w;
//	for (int i = 0; i < nums.size();++i){
//		for (int j = i+1; j < nums.size();j++){
//			if (nums[i] + nums[j] == target){
//				w.push_back(i);
//				w.push_back(j);
//				return w;
//			}
//		}
//	}
//}
//
//int main(){
//	vector<int> w = { 3,2,4 };
//	twoSum(w, 7);
//	return 0;
//}