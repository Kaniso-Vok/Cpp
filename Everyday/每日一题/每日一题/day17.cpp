#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//int fun(int n){
//	int a[50][50] = {0};
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < 2*i + 1; j++){
//			if (i == 0 || j == 0 || j == 2 * i){
//				a[i][j] = 1;
//			}
//			else if (j == 1){
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//			}
//			else{
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j - 2];
//			}
//		}
//	}
//	for (int i = 0; i < ((2*(n-1)+1) / 2); ++i){
//		if (a[n - 1][i] % 2 == 0){
//			return i + 1;
//		}
//	}
//	return -1;
//}
//int main(){
//	int n;
//	while (cin >> n){
//		cout << fun(n) << endl;
//	}
//	return 0;
//}

//超长正整数相加
//string AddLongInteger(string addend, string augend){
//	int i = 0,n=addend.size()>augend.size()?n=addend.size():n=augend.size();  //n为较长计算值的长度，用来循环计算时使用
//	string c;              //计算结果保存的值
//	int  temp, tep = 0;         //进位值要记得初始化
//	reverse(addend.begin(), addend.end());         //这里将两个加数都翻转过来计算，主要是为了写入结果的时候可以直接使用‘+=’
//	reverse(augend.begin(), augend.end());         //当然也可以没有这一步，直接从后往前算
//	for (; i < n; i++){
//		int a = i<addend.size() ? addend[i] - '0' : 0;         //若是一个加数已经全部计算完成，在接下来就用0代替来计算
//	    int b = i<augend.size() ? augend[i] - '0' : 0;
//		temp = (a+b+tep)% 10;           //计算结果值（要填入结果的值）
//		tep = (a + b + tep) / 10;   //进位值
//		c += temp + 48;  // 填入结果
//	}
//	if (tep>0){    //若是最后一位计算有进位值，则直接填入结果
//		c += tep+'0';
//	}
//	reverse(c.begin(), c.end());   //将计算结果反过来就是正确结果
//	return c;
//}
//
//int main(){
//	string a, b, c;
//	while (cin >> a >> b){
//		cout << AddLongInteger(a, b) << endl;
//	}
//	return 0;
//}