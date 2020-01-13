#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
//bool isPalindrome(int x) {
//	string s1 = to_string(x);
//	string s2 = s1;
//	reverse(s2.begin(), s2.end());
//	if (s1 == s2) return true;
//	return false;
//}
//int main(){
//	int x = 1212;
//	isPalindrome(x);
//	return 0;
//}

//bool canConstruct(string ra, string ma) {
//	int key[26] = {0};
//	for (int i = 0; i < ma.size(); ++i){
//		key[ma[i] - 'a']++;
//	}
//	for (int i = 0; i < ra.size(); ++i){
//		if (--key[ra[i] - 'a'] < 0){
//			return false;
//		}
//	}
//	return true;
//}
//int main(){
//	canConstruct("aa", "ab");
//	return 0;
//}
//int main(){
//	int i = 0, a = 0;
//	while (i<20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0) break;
//			else i--;
//		}
//		i += 11; a += i;
//	}
//	cout << a ;
//	return 0;
//}