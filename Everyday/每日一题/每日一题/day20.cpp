#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//int main(){
//	string s;
//	while (cin >> s){
//		reverse(s.begin(), s.end());
//		cout << s << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<string>s(2);
	for (int i = 0; i < 2; i++){
		cin >> s[i];
	}
	int z1 = s[0].size(),z2=s[1].size();
	int sum=0,max=0;
	if (z1>z2){
		auto it = s[0].begin(),it1=s[1].begin();
		for (; it != s[0].end()||it1!=s[1].begin(); it++){
			if (*it == *it1){
				sum++;
			}
			else{
				if (sum > max){
					max = sum;
					sum = 0;
					it1 = s[1].begin();
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}