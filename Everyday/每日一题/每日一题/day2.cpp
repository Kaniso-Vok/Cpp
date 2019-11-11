#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//erase 的使用注意的点
//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//	vector<int> a;
//	a.push_back(100);
//	a.push_back(300);
//	a.push_back(300);
//	a.push_back(300);
//	a.push_back(300);
//	a.push_back(500);
//	auto it = a.begin();
//	for (; it != a.end(); it++){
//		if (*it == 300){
//			it = a.erase(it);
//		}
//	}
//	for (it = a.begin(); it != a.end(); it++){
//		cout << *it << ' ';
//	}
//	return 0;
//}

//int main(){
//	int i = 0;
//
//	return 0;
//}
//#include <string>
//#include <algorithm>
//int main(){
//	string s;
//	getline(cin, s);      //输入的字符串中包含空格，所以不能使用cin输入（遇到空格会停止），使用getline读取全部的字符（遇到换行符、EOF、自定义符号停止）
//	auto it = s.begin();  //本体我选择用迭代器进行遍历字符串
//	reverse(s.begin(), s.end());    //第一步先将整个字符串逆置，之后再分别将每一个单词逆置
//	while (it!=s.end()){
//		auto ii = it;
//		while (ii != s.end() && *ii != ' '){    //找到一个单词的结束位置
//			ii++;
//		}
//		reverse(it, ii);                    //逆置当前单词
//		if (ii != s.end()){          
//			it = ii + 1;               //重新定义下一个单词的开头位置，+1是因为单词之间只有一个‘ ’
//			ii++;
//		}
//		else{                         //若当前是最后一个位置，则直接给予结束条件结束循环
//			it = s.end();
//		}
//	}
//	cout << s;        //输出结果
//	return 0;
//}
//
////大佬扩展
//#include<string>
//int main()
//{
//	string s1;
//	string s2;
//
//	cin >> s1;
//
//	while (cin >> s2&&getchar() != '\n')
//	{
//		s1 = s2 + " " + s1;
//	}
//
//	cout << s2 << " " << s1 << endl;
//	return 0;
//}


//输入的数列可以分为多少段有序序列
//#include<vector>
//int main(){
//	int i=0,n, sum=0;
//	vector<int> a;
//	cin >> n;
//	a.resize(n+1);
//	for (int m = 0; m < n; ++m){
//		cin >> a[m];
//	}
//	while (i < n){
//		if (a[i + 1]>a[i]){
//			while (i<n&&a[i + 1]>a[i]){
//				i++;
//			}
//			sum++;
//			i++;
//		}
//		else if (a[i + 1] < a[i]){
//			while (i<n&&a[i + 1]<a[i]){
//				i++;
//			}
//			sum++;
//			i++;
//		}
//		else{
//			i++;
//		}
//	}
//	cout << sum;
//  	return 0;
//}