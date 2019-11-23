//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Board {              //以二维数组作棋盘的三子棋（井字棋）胜利条件判断
//public:
//	bool checkWon(vector<vector<int> > arr) {
//		int n, m;
//		for (n = 0; n<3; n++){
//			if (arr[n][0] + arr[n][1] + arr[n][2] == 3){
//				return true;
//			}
//			if (arr[0][n] + arr[1][n] + arr[2][n] == 3){
//				return true;
//			}
//		}
//		if (arr[0][0] + arr[1][1] + arr[2][2] == 3 || arr[0][2] + arr[1][1] + arr[2][0] == 3){
//			return true;
//		}
//		return false;
//	}
//};

//辨识密码强度
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int get(string str)
//{
//	int sum = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
//	vector<char>a21, a22, a31, a41;
//
//	int len = str.size();
//	if (len <= 4)a1 = 5;
//	else if (len >= 8)a1 = 25;
//	else a1 = 10;
//
//	for (int i = 0; i<len; ++i)
//	if (str[i] <= 'z'&&str[i] >= 'a')a21.push_back(str[i]);
//	else if (str[i] <= 'Z'&&str[i] >= 'A')a22.push_back(str[i]);
//	else if (str[i] <= '9'&&str[i] >= '0')a31.push_back(str[i]);
//	else a41.push_back(str[i]);
//	int lena21 = a21.size(), lena22 = a22.size(), lena31 = a31.size(), lena41 = a41.size();
//
//	if (lena21 == 0 && lena22 == 0)a2 = 0;
//	else if (lena21 != 0 && lena22 != 0)a2 = 20;
//	else a2 = 10;
//
//	if (lena31 == 0)a3 = 0;
//	else if (lena31 == 1)a3 = 10;
//	else a3 = 20;
//
//	if (lena41 == 0)a4 = 0;
//	else if (lena41 == 1)a4 = 10;
//	else a4 = 25;
//
//	if (lena21&&lena22&&lena31&&lena41)a5 = 5;
//	else if ((lena21 || lena22) && lena31&&lena41)a5 = 3;
//	else if ((lena21 || lena22) && lena31)a5 = 2;
//	else a5 = 0;
//
//	sum = a1 + a2 + a3 + a4 + a5;
//	return sum;
//}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int sum = get(str);
//		switch (sum / 10)
//		{
//		case 9:cout << "VERY_SECURE" << endl; break;
//		case 8:cout << "SECURE" << endl; break;
//		case 7:cout << "VERY_STRONG" << endl; break;
//		case 6:cout << "STRONG" << endl; break;
//		case 5:cout << "AVERAGE" << endl; break;
//		default:
//		{
//				   if (sum >= 25)cout << "WEAK" << endl;
//				   else cout << "VERY_WEAK" << endl;
//		}
//		}
//	}
//	return 0;
//}