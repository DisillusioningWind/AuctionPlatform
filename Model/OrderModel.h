#pragma once
#include "../Global.h"

class OrderModel
{
public:
	string orderID;//4 char,T+xxx
	string commodityID;//4 char,M+xxx
	double unitPrice;//>0
	int number;
	string date;//yyyy-mm-dd
	string sellerID;//4 char,U+xxx
	string buyerID;//4 char,U+xxx

	OrderModel();
	OrderModel(string oid, string cid, double pri, int num, string dt, string sid, string bid);
};