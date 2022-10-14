#include "CommodityModel.h"

CommodityModel::CommodityModel()
{
	commodityID = "";
	commodityName = "";
	price = 0;
	number = 0;
	description = "";
	sellerID = "";
	addedDate = "";
	state = false;
}
CommodityModel::CommodityModel(string id, string name, double pri, int num, string des, string sid, string date, bool st, time_t tm)
{
	commodityID = id;
	commodityName = name;
	price = pri;
	number = num;
	description = des;
	sellerID = sid;
	addedDate = date;
	state = st;
	time = tm;
}