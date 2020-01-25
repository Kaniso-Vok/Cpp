#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
	int sta = 0, end = nums.size() - 1;
	vector<vector<int>> res;
	res.push_back({});
	for (; sta <= end; sta++){
		vector<int> ss;
		for (int i = sta; i <= end; ++i){
			for (int j = sta; j <= i; j++){
				ss.push_back(nums[j]);
			}
			res.push_back(ss);
			ss.clear();
		}
		
	}
	return res;
}

int main(){
	vector<int> k = { 1, 2, 3 };
	subsets(k);
	return 0;
}