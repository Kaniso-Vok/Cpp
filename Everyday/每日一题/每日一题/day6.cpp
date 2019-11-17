#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	int w, h, res = 0;
//	cin >> w >> h;
//	vector<vector<int>> a;
//	a.resize(w);
//	for (auto& e : a)
//		e.resize(h, 1);
//
//	for (int i = 0; i<w; i++)
//	{
//		for (int j = 0; j<h; j++)
//		{
//			if (a[i][j] == 1)
//			{
//				res++;
//				// 标记不能放蛋糕的位置
//				if ((i + 2)<w)
//					a[i + 2][j] = 0;
//
//				if ((j + 2)<h)
//					a[i][j + 2] = 0;
//			}
//		}
//	}
//	cout << res;
//	return 0;
//}

//会产生溢出问题（未解决
//#include<string>
//int main(){
//	int sum = 0,sym=1;
//	string s;
//	cin >> s;
//	if (s.empty()){
//		return 0;
//	}
//	if (s[0] == '-'){
//		sym = -1;
//		s[0] = '0';
//	}
//	if (s[0] == '+'){
//		sym = 1;
//		s[0] = '0';
//	}
//	for (int i = 0; i < s.length(); ++i){
//		if (s[i] >= '0'&&s[i] <= '9'){
//			sum = sum * 10 + s[i] - '0';
//		}
//		else{
//			sum = 0;
//			break;
//		}
//	}
//	cout << sym*sum;
//	return 0;
//}