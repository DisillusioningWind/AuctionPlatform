#include "UserBidModel.h"

UserBidModel::UserBidModel(double off, int num, string bid, time_t tm)
{
	offer = off;
	number = num;
	bidUserID = bid;
	time = tm;
}