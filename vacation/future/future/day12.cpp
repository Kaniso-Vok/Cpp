#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
	vector<int>w = nums;
	sort(begin(w), end(w));
	int i = 0, j = w.size()-1;
	for (int v : w){
		if (v != nums[i]){
			break;
		}
		i++;
	}
	if (i-1 == j){
		return 0;
	}
	for (; j > 0; j--){
		if (w[j] != nums[j]){
			break;
		}
	}
	return j-i+1;
}

int main(){
	vector<int> w = { 1,2,3,4 };
	findUnsortedSubarray(w);
	return 0;
}
