#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string str1, str2;
	while (cin >> str1 >> str2){
		if (str1.size() > str2.size()){
			swap(str1, str2);
		}
		int le1 = str1.size(), le2 = str2.size(),max=0,sta=0;
		vector<vector<int>> str(le1 + 1, vector<int>(le2 + 1, 0));
		for (int i = 1; i <= le1; ++i){
			for (int j = 1; j <= le2; ++j){
				if (str1[i-1] == str2[j-1]){
					str[i][j] = str[i - 1][j - 1] + 1;
				}
				if (str[i][j]>max){
					max = str[i][j];
					sta = i - max;
				}
			}
		}
		cout << str1.substr(sta,max) << endl;    
	}
	return 0;
}





/*
递归问题
3个瓶子换1瓶水+1个空瓶子，两个瓶子换1瓶水+0个空瓶子，1个瓶子换0瓶水。
f(1) = 0
f(2) = 1
f(3) = 1
f(4) = f(2)+1    //4个瓶子，其中3个可以换1瓶水+1个空瓶，所以是f(2)+1
f(5) = f(3)+1    //3个瓶子换1瓶水+1个空瓶，所以是f(3)+1
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

