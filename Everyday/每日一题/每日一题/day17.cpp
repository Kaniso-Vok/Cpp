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

//�������������
//string AddLongInteger(string addend, string augend){
//	int i = 0,n=addend.size()>augend.size()?n=addend.size():n=augend.size();  //nΪ�ϳ�����ֵ�ĳ��ȣ�����ѭ������ʱʹ��
//	string c;              //�����������ֵ
//	int  temp, tep = 0;         //��λֵҪ�ǵó�ʼ��
//	reverse(addend.begin(), addend.end());         //���ｫ������������ת�������㣬��Ҫ��Ϊ��д������ʱ�����ֱ��ʹ�á�+=��
//	reverse(augend.begin(), augend.end());         //��ȻҲ����û����һ����ֱ�ӴӺ���ǰ��
//	for (; i < n; i++){
//		int a = i<addend.size() ? addend[i] - '0' : 0;         //����һ�������Ѿ�ȫ��������ɣ��ڽ���������0����������
//	    int b = i<augend.size() ? augend[i] - '0' : 0;
//		temp = (a+b+tep)% 10;           //������ֵ��Ҫ��������ֵ��
//		tep = (a + b + tep) / 10;   //��λֵ
//		c += temp + 48;  // ������
//	}
//	if (tep>0){    //�������һλ�����н�λֵ����ֱ��������
//		c += tep+'0';
//	}
//	reverse(c.begin(), c.end());   //��������������������ȷ���
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