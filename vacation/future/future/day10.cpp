#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//vector<int> searchRange(vector<int>& nums, int target) {
//	int i = 0;
//	vector<int> res;
//	if (nums.size() == 0){
//		res.push_back(-1);
//		res.push_back(-1);
//		return res;
//	}
//	for (int e : nums){
//		if (e == target){
//			break;
//		}
//		else if (e>target || (target>e && i == nums.size() - 1)){
//			res.push_back(-1);
//			res.push_back(-1);
//			return res;
//		}
//		i++;
//	}
//	res.push_back(i);
//	for (; i<nums.size(); ++i){
//		if (nums[i] != target){
//			break;
//		}
//	}
//	res.push_back(i - 1);
//	return res;
//}
//
//int main(){
//	vector<int> w = { 5,7,7,8,8,10 };
//	searchRange(w, 8);
//	return 0;
//}




//int myAtoi(string str) {
//	int i = 0;
//	long long int result = 0;
//	bool pm = true;
//	while (str[i] == ' '){
//		i++;
//	}
//	if (i == str.size()){
//		return 0;
//	}
//	if (str[i] == '-'){
//		pm = false;
//		i++;
//	}
//	else if (str[i] == '+'){
//		i++;
//	}
//	while (i < str.size() && isdigit(str[i]) != 0){
//		result = result * 10 + str[i++] - '0';
//		if (result >= 2147483648){
//			if (pm != false){
//				return INT_MAX;
//			}
//			else{
//				return INT_MIN;
//			}
//		}
//	}
//	if (pm == false){
//		result = -result;
//	}
//	return result;
//}
//
//int main(){
//	int key = myAtoi("47");
//	return 0;
//}

//int a, b;
//void fun()
//{
//	a = 100;
//	b = 200;
//}
//int main()
//{
//	int a = 5, b = 7;
//	fun();
//	printf("% d % d / n", a, b);
//	return 0;
//}