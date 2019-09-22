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
int main()
{
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
//	//int& nn;//应用必须初始化
//	//cout << a << endl;
//	//cout << n1::c << endl;
//	//func(1, 1, 1);
//	//func(1);
//	//cout << add() << endl;
//	//cout << add(22) << endl;//仅仅是缺省值不同无法构成函数重载
//	system("pause");
//}