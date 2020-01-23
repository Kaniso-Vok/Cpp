#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int compress(vector<char>& chars) {
//	int n = chars.size();
//	int cur = 0;
//	for (int i = 0, j = 0; i < n; j = i) {      //双指针，i先数，数完跟j
//		while (i < n && chars[i] == chars[j]) {  //数i
//			i++;
//		}
//		chars[cur++] = chars[j];  //更新头字符，比如{a,3,b,3}中a和b为头字符
//		if (i - j == 1) {    //若是当前字符只有一个，不需压缩
//			continue;
//		}
//		string s = to_string(i - j);   //将个数（数字）转化为字符
//		for (int t = 0; t < s.size(); t++) {
//			chars[cur++] = s[t];   //写入字符个数
//		}
//	}
//	return cur;
//}
//
//int main(){
//	vector<char> w = { 'a','a','a','b','b','b' };
//	compress(w);
//	return 0;
//}

//bool isPalindrome(string s) {
//	int i = 0, j = s.size() - 1;
//	bool res = true;
//	vector<char> svec;
//	for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]); 
//	for (int i = 0; i < s.length(); i++)
//	if (isalpha(s[i]) || isdigit(s[i]))
//		svec.push_back(s[i]);
//	for (int i = 0, j = svec.size() - 1; i<j; i++, j--)
//	if (svec[i] != svec[j]) return false;
//	else continue;
//	return true;
//}
//
//int main(){
//	
//	return 0;
//}