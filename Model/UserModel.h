#pragma once
#include "../Global.h"

class UserModel
{
public:
	string userID;//4 char,U+xxx
	string userName;//no more than 10 char
	string passWord;//no more than 20 char
	string phoneNumber;//no more than 20 char
	string address;//no more than 40 char
	double balance;
	bool userState;//include active,inactive

	UserModel();
	UserModel(string id, string name, string pwd);
	UserModel(string id, string name, string pwd, string ph, string add, double bal, bool st);
};