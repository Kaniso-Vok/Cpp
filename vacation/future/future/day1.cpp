//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		int sum = 0, s = nums.size();
//		int i = s - k%s;
//		if (s <= 1){
//			return;
//		}
//		vector<int> w;
//		while (sum < s){
//			if (i > s-1){
//				i = i-s;
//			}
//			w.push_back(nums[i]);
//			i++;
//			sum++;
//		}
//		nums = w;
//	}
//};
//int main(){
//	Solution L;
//	vector<int> k = { 1, 2,3,4,5,6,7};
//	L.Solution::rotate(k, 3);
//	for (auto e : k){
//		cout << e << ' ';
//	}
//	return 0;
//}
