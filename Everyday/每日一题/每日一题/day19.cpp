#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
�ݹ�����
3��ƿ�ӻ�1ƿˮ+1����ƿ�ӣ�����ƿ�ӻ�1ƿˮ+0����ƿ�ӣ�1��ƿ�ӻ�0ƿˮ��
f(1) = 0
f(2) = 1
f(3) = 1
f(4) = f(2)+1    //4��ƿ�ӣ�����3�����Ի�1ƿˮ+1����ƿ��������f(2)+1
f(5) = f(3)+1    //3��ƿ�ӻ�1ƿˮ+1����ƿ��������f(3)+1
...
f(n) = f(n-2)+1 */
//#include <iostream>
//
//using namespace std;
//
//int f(int n)
//{
//	if (n == 1) return 0;
//	if (n == 2) return 1;
//	return f(n - 2) + 1;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n){
//		if (n == 0)
//			break;
//		cout << f(n) << endl;
//	}
//	return 0;
//}