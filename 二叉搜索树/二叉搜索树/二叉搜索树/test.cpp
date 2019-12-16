#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"BsTree.h"
using namespace std;
void Bstree(){
	BStree<int> a;
	a.Insert(4);
	a.Insert(5);
	a.Insert(6);
	a.Insert(1);
	a.Insert(2);
	a.Insert(3);
	a.Insert(9);
	a.Insert(8);
	a.Insert(7);
	a.Insert(10);
	a.Insert(13);
	a.Insert(0);
	a.InOrder();
	cout<<a.IfLeftMost()->date_<<endl;
	cout << a.IfRightMost()->date_ << endl;
	//a.Delete(3);
	//a.InOrder();
	//a.Delete(10);
	//a.InOrder();
	//a.Delete(0);
	//a.InOrder();
	//a.Delete(13);
	//a.InOrder();

}
int main(){
	Bstree();
	return 0;
}