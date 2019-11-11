#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//int main(){
//
//	return 0;
//}

//找出字符串中最长的数字串
//#include<string>
//void FFind(string s){
//	auto it = s.begin();
//	string a,res;
//	while (it != s.end()){
//		if (*it >= 48 && *it <= 57){
//			a =a + *it;
//		}
//		else{
//			if (a.size() > res.size()){
//				res = a;
//				a.clear();
//			}
//			else{
//				a.clear();
//			}
//		}
//		it++;
//	}
//	if (a.size() > res.size()){
//		res = a;
//	}
//	cout << res;
//}
//int main(){
//	string s;
//	getline(cin, s);
//	FFind(s);
//	return 0;
//}
//
//优化版本:
//
//#include<string>
//
//int main()
//{
//	string s, res, cur;
//	cin >> s;
//	for (int i = 0; i <= s.length(); i++)
//	{
//		 数字+=到cur
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			cur += s[i];
//		}
//		else
//		{
//			 找出更长的字符串，则更新字符串
//			if (res.size() < cur.size())
//				res = cur;
//			else
//				cur.clear();
//		}
//	}
//	cout << res;
//	return 0;
//}
