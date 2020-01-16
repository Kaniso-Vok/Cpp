#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//string reverseOnlyLetters(string S) {
//	int len=0;
//	string w;
//	for (char e : S){
//		if (e >= 65 && e <= 90 || e >= 97 && e <= 122){
//			w.push_back(e);
//		}
//	}
//	auto it = rbegin(w);
//	for (int i = 0; i < S.size(); ++i){
//		if (S[i] >= 65 && S[i] <= 90 || S[i] >= 97 && S[i] <= 122){
//			S[i] = *it;
//			it++;
//		}
//	}
//	return S;
//}
//
//int main(){
//	reverseOnlyLetters("ab-cd");
//	return 0;
//}


//vector<int> sortedSquares(vector<int>& A) {
//	vector<int> w;
//	w = A;
//	for (int i = 0; i < w.size(); ++i){
//		w[i] *= w[i];
//	}
//	sort(begin(w), end(w));
//	return w;
//}
//
//int main(){
//	vector<int> a = { -4, -1, 0, 3, 10 };
//	sortedSquares(a);
//	return 0;
//}