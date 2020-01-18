#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int thirdMax(vector<int>& nums) {
	set<int> w;
	for (int e : nums){
		w.insert(e);
		if (w.size() > 3){
			w.erase(*(begin(w)));
		}
	}
	if (w.size() < 3){
		return *(rbegin(w));
	}
	else{
		return *(begin(w));
	}
}

int main(){
	vector<int> w = { 1,1,2 };
	int k=thirdMax(w);
	return 0;
}

//vector<int> plusOne(vector<int>& digits) {
//	for (int i = digits.size() - 1; i >= 0; i--){
//		if (digits[i] == 9){
//			digits[i] = 0;
//		}
//		else{
//			digits[i]++;
//			break;
//		}
//	}
//	if (digits[0] == 0){
//		digits.push_back(0);
//		digits[0] = 1;
//	}
//	return digits;
//}
//
//int main(){
//	vector<int> w = { 9,9,9 };
//	plusOne(w);
//	return 0;
//}