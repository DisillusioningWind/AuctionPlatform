#pragma once
#include "../Global.h"

class CommodityModel
{
public:
	string commodityID;//4 char,M+xxx
	string commodityName;//no more than 20 char
	double price;
	int number;
	string description;//no more than 200 char
	string sellerID;//4 char,U+xxx
	string addedDate;//yyyy-mm-dd
	time_t time;
	bool state;//include removed,onAuction

	CommodityModel();
	CommodityModel(string id, string name, double pri, int num, string des, string sid, string date, bool st, time_t tm);
};