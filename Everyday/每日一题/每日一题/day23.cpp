#define _CRT_SECURE_NO_WARNINGS 1
//典型的动态规划优化编辑器问题
//参考博客 http://blog.csdn.net/shizheng163/article/details/50988023
#include<iostream>
#include <string>
#include <vector>
using namespace std;


//class Gift {
//public:
//	int getValue(vector<int> g, int n) {
//		int a[11] = {0};
//		for (auto it = g.begin(); it != g.end(); it++){
//			a[*it - 1]++;
//		}
//		for (int i = 0; i < sizeof(a); i++){
//			if (a[i]>(g.size() / 2)){
//				return i + 1;
//			}
//		}
//		return 0;
//	}
//};
//int main(){
//	vector<int> a = {1,2,3,2,2};
//	int n = 5;
//	Gift b;
//	int result=b.getValue(a, 5);
//	cout << result << endl;
//	return 0;
//}
//连续最大和
//#include <iostream>
//using namespace std;
//int main(){
//	int n, curSum = 0, maxSum = -1e5;
//	cin >> n;
//	int arr[n];
//	for (int i = 0; i<n; i++){
//		cin >> arr[i];
//		curSum += arr[i];
//		if (curSum>maxSum){
//			maxSum = curSum;
//		}
//		if (curSum<0){
//			curSum = 0;
//		}
//	}
//	cout << maxSum << endl;
//	return 0;
//}

//int calStringDistance(string a, string b){
//	int n = (int)a.size(), m = (int)b.size();
//	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
//	dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
//	for (int i = 1; i <= m; ++i) dp[0][i] = i;
//	for (int i = 1; i <= n; ++i) dp[i][0] = i;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			int one = dp[i - 1][j] + 1, two = dp[i][j - 1] + 1, three = dp[i - 1][j - 1];
//			if (a[i - 1] != b[j - 1]) three += 1;
//			dp[i][j] = min(min(one, two), three);
//		}
//	}
//	return dp[n][m];
//}
//int main(){
//	string a, b;
//	while (cin >> a >> b)
//		cout << calStringDistance(a, b) << endl;
//	return 0;
//}