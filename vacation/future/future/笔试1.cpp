#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//
//��һ�������������� n �� root��n ��ʾ���������ܽڵ������root ��ʾ�������ĸ��ڵ㡣
//���� n ��ÿ���������� fa��lch��rch����ʾ fa �������Ϊ lch���Ҷ���Ϊ rch��(��� lch Ϊ 0 ���ʾ fa û������ӣ�rchͬ��)
//�������
//�����ƽ������������ "true"��������� "false"��

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