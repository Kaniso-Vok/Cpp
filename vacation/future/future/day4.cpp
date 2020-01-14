#define _CRT_SECURE_NO_WARNINGS 1
//#define N 2
//#define M N+1
//#define NUM (M+1)*M/2
#include<string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	for (int i = m, j = 0; i<m + n, j<n; ++i, ++j){
		nums1[i] = nums2[j];
	}
	sort(nums1.begin(), nums1.end());
}

//int lengthOfLastWord(string s) {
//	int len = 0;
//	for (int i = s.size(); i > 0; i--){
//		if (s[i] != ' '){
//			len++;
//		}
//		else if (len != 0){
//			return len;
//		}
//	}
//	return len;
//}
//
//int main()
//{
//	string s="af qfqe sdg qrq qwrqwrqrq";
//	cout << lengthOfLastWord(s);
//	return 0;
//}

