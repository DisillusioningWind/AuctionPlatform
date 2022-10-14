#include "UserModel.h"

UserModel::UserModel()
{
	userID = "";
	userName = "";
	passWord = "";
	phoneNumber = "";
	address = "";
	balance = 0;
	userState = true;
}
UserModel::UserModel(string id, string name, string pwd)
{
	userID = id;
	userName = name;
	passWord = pwd;
	phoneNumber = "";
	address = "";
	balance = 0;
	userState = true;
}
UserModel::UserModel(string id, string name, string pwd, string ph, string add, double bal, bool st)
{
	userID = id;
	userName = name;
	passWord = pwd;
	phoneNumber = ph;
	address = add;
	balance = bal;
	userState = st;
}
