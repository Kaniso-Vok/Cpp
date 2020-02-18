#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//
//第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。
//以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)
//输出描述
//如果是平衡二叉树则输出 "true"，否则输出 "false"。

//3  2
//1  2  3

int main(){
	int n, root,fa,lch,rch;
	cin >> n >> root;
	for (int i = 0; i < n-1; ++i){
		cin >> fa >> lch >> rch;
	}
	cout << Judge(root);
	return 0;
}
















//
//void qs(int* arr,int left,int right){
//	if (left<right){
//		int key = arr[left];
//		int low = left, high = right;
//		while (low < high){
//			while (key<=arr[high] && low < high){
//				high--;
//			}
//			arr[low] = arr[high];
//			while (key>=arr[low] && low < high){
//				low++;
//			}
//			arr[high] = arr[low];
//		}
//		arr[low] = key;
//		qs(arr, left, low - 1);
//		qs(arr, low+1, right);
//	}
//}
//
//
//
//int main() {
//	int arr[] = { 33, 14, 2, 444, 23, 444, 132, 55, 0 };
//	qs(arr, 0, sizeof(arr) / sizeof(arr[0])-1);
//	for (int i = 0; i<sizeof(arr) / sizeof(arr[0]); ++i){
//		cout << arr[i] << ' ';
//	}
//	return 0;
//}


//void solve(string& str1,string& str2){
//	string str;
//	for (int i = 0; i < str1.size(); ++i){
//		if (str2.find(str1[i])==-1){
//			str.push_back(str1[i]);
//		}
//	}
//	cout << str;
//	return;
//}
//
//int main(){
//	string s1, s2;		
//	getline(cin, s1);
//	getline(cin, s2);
//	solve(s1, s2);
//	return 0;
//}
//
//int main(){
//	int n, mmax = -1e10, max = 0;
//	cin >> n;
//	int arr[100000];
//	for (int i = 0; i < n; ++i){
//		cin >> arr[i];
//	}
//	int m = 0;
//	while (m<n){
//		max += arr[m];
//		if (max>mmax){
//			mmax = max;
//		}
//		if (max < 0 && m != (n - 1)){
//			max = 0;
//		}
//		m++;
//	}
//	cout << mmax;
//	return 0;
//}