#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"C++.h"
using namespace std;
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//Date d1;	�޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ����ע�⣺�޲�
	/*���캯����ȫȱʡ���캯��������ûд������Ĭ�����ɵĹ��캯������������Ϊ��Ĭ�ϳ�Ա����
	*/
	A* p = NULL;
	p->PrintA();
	p->Show();
}
//namespace n1
//{
//	int a = 10;
//	double c = 11.11;
//	int add(int a1, int a2)
//	{
//		return a1 + a2;
//	}
//}
//void func(int a, int b = 10, int c = 22)
//{
//	cout << a << endl<<b<<endl<<c<<endl;
//}
//void Spp::pp()
//{
//	cout << a << endl << b << endl << c;
//}
////int add(int a = 10)
////{
////	return a;
////}
////int add(int a)
////{
////	return a;
////}
//int& Add(int& aa, int& bb)
//{
//	aa = aa + bb;
//	return aa;
//}
//using n1::a;
//int main()
//{
//	int a = 10,b=2;
//	int& aa = a;
//	
//	/*cout << aa << endl << a << endl;*/
//	
//	//int& ret = Add(a, b);
//	//cout << ret << endl;
//	//a = 1, b = 1;
//	//Add(a, b);
//
//	//cout << "Add(1, 2) is :" << ret << endl;
//	//int& nn;//Ӧ�ñ����ʼ��
//	//cout << a << endl;
//	//cout << n1::c << endl;
//	//func(1, 1, 1);
//	//func(1);
//	//cout << add() << endl;
//	//cout << add(22) << endl;//������ȱʡֵ��ͬ�޷����ɺ�������
//	system("pause");
//}