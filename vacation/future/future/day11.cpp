#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int compress(vector<char>& chars) {
//	int n = chars.size();
//	int cur = 0;
//	for (int i = 0, j = 0; i < n; j = i) {      //˫ָ�룬i�����������j
//		while (i < n && chars[i] == chars[j]) {  //��i
//			i++;
//		}
//		chars[cur++] = chars[j];  //����ͷ�ַ�������{a,3,b,3}��a��bΪͷ�ַ�
//		if (i - j == 1) {    //���ǵ�ǰ�ַ�ֻ��һ��������ѹ��
//			continue;
//		}
//		string s = to_string(i - j);   //�����������֣�ת��Ϊ�ַ�
//		for (int t = 0; t < s.size(); t++) {
//			chars[cur++] = s[t];   //д���ַ�����
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