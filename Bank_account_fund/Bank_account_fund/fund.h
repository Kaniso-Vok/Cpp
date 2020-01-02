#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "stdafx.h"
using namespace std;

class Login
{

};

class Consumer
{
	Consumer(){};
	Consumer(string bank_name, int id, string name, string telphone, string password, float money){};
	void draw_money(float money){};
	void save_money(float money){};
	void trans_acc(int id1, int id2){};
	void change_passwd(int id, string password){};
	void search(int id){};
	void history(){};
private:
	string _bank_name;
	int _id;
	string _name;
	string _telphone;
	string _password;
	float _money;
};