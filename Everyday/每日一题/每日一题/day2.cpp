#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//erase ��ʹ��ע��ĵ�
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
//	getline(cin, s);
//	auto it = s.begin();
//	reverse(s.begin(), s.end());
//	while (it!=s.end()){
//		auto ii = it;
//		while (ii != s.end() && *ii != ' '){
//			ii++;
//		}
//		reverse(it, ii);
//		if (ii != s.end()){
//			it = ii + 1;
//			ii++;
//		}
//		else{
//			it = s.end();
//		}
//	}
//	cout << s;
//	return 0;
//}

//������չ
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


//��������п��Է�Ϊ���ٶ���������
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