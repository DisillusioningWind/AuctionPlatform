#pragma once
#include "../Global.h"
class UserBidModel
{
public:
	double offer;
	int number;
	string bidUserID;
	time_t time;

	UserBidModel(double off, int num, string bid, time_t tm);
};

