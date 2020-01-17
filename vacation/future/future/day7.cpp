#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//int pivotindex(vector<int>& nums) {
//	int sum = 0;
//	for (int item : nums)
//		sum += item;
//	cout << "sum = " << sum << endl;
//	int sum_left = 0;
//	for (int i = 0; i<nums.size(); i++) {
//		if (sum_left == sum - sum_left - nums[i])
//			return i;
//		sum_left += nums[i];
//	}
//	return -1;
//}

//vector<int> sortArrayByParity(vector<int>& A) {
//	vector<int> w;
//	for (int e : A){
//		if (e % 2 == 0 && e != 0){
//			w.push_back(e);
//		}
//	}
//	for (int e : A){
//		if (e %== 0){
//			w.push_back(e);
//		}
//	}
//	for (int e : A){
//		if (e % 2 != 0){
//			w.push_back(e);
//		}
//	}
//	return w;
//}
//
//int main()
//{
//	vector<int> w = { 1,0 };
//	sortArrayByParity(w);
//	return 0;
//}

//int main(){
//	char *p = "abcdefgh", *r;
//	long *q;
//	p++;
//	q = (long*)p;
//	q++;
//	r = (char*)q;
//	printf("%s\n", r);
//	return 0;
//}