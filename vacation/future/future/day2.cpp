#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//int searchInsert(vector<int>& nums, int target) {
//	for (int i = 0; i < nums.size(); ++i){
//		if (nums[i]>=target){
//			return i;
//		}
//	}
//	return nums.size();
//}
//
//int main(){
//	vector<int> w = { 1, 3, 5, 6, };
//	cout << searchInsert(w, 2);
//	return 0;
//}


//int removeElement(vector<int>& nums, int val) {
	//int m = 0;
	//for (int n = 0; n < nums.size(); ++n){
	//	if (nums[n] != val){
	//		nums[m] = nums[n];
	//		m++;
	//	}
	//}
	//return m;
//}
//
//int main(){
//	vector<int> w = { 3, 5, 1, 2, 5, 6, 3, 34, 326, 46, 4, 3 };
//	int k = 3;
//	cout << removeElement(w, k);
//	return 0;
//}