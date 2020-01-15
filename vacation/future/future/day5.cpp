#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
//bool isLongPressedName(string name, string typed) {
//	int x = name.size(),y=0;
//	for (int i = 0; i < x; i++){
//		while (name[i] == name[i + 1]){
//			i++;
//			y++;
//		}
//		int z = y;
//		while (typed[y] == name[i]){
//			y++;
//		}
//		if (z == y){
//			return false;
//		}
//	}
//	return true;
//}
//
//int main(){
//	bool key;
//	key = isLongPressedName("saeed", "ssaaedd");
//	return 0;
//}

//bool containsDuplicate(vector<int>& nums) {
//	auto it = begin(nums);
//	for (int i = 0; i < nums.size(); ++i){
//		if (find(it + 1, end(nums), nums[i]) != end(nums)){
//			return true;
//		}
//		it++;
//	}
//	return false;
//}
//
//int main(){
//	vector<int> w = { 1, 2, 3, 2, 5 };
//	containsDuplicate(w);
//	return 0;
//}

//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	}
//	return b;
//}
//int main(){
//	cout << func(1);
//	return 0;
//}