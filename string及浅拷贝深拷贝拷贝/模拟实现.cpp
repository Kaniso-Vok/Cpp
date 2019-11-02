#define _CRT_SECURE_NO_WARNINGS 1
//基础模拟实现
#include<iostream>
#include<assert.h>
using namespace std;

namespace self{
	class string{
	public:
		string(const char* s = " "){
			if (s == nullptr){
				assert(false);
				return;
			}
			_s = new char[strlen(s) + 1];
			strcpy(_s, s);
		}
		~string(){
			if (_s){
				delete[] _s;
				_s = nullptr;
			}
		}
	private:
		char* _s;
	};
}
int main(){
	self::string k = "hello";
	self::string i("world");
	self::string m;
	//self::string l(k);
	return 0;
}