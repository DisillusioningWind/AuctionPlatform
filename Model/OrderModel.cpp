#include "OrderModel.h"

OrderModel::OrderModel()
{
	unitPrice = 0;
	number = 0;
}
OrderModel::OrderModel(string oid, string cid, double pri, int num, string dt, string sid, string bid)
{
	orderID = oid;
	commodityID = cid;
	unitPrice = pri;
	number = num;
	date = dt;
	sellerID = sid;
	buyerID = bid;
}