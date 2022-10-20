#include "PlatformController.h"

//Generate new id and order
template <class Tmap>
string PlatformController::GenerateNewID(Tmap mp, string type)
{
	int subID = mp.size() + 1;
	//format to U+xxx
	string newID = type + to_string(subID);
	for (int len = newID.length(); len < 4; len++)
	{
		newID.insert(1, "0");
	}
	return newID;
}
bool PlatformController::GenerateNewUser(string name, string pwd)
{
	string newID = GenerateNewID(users, "U");
	UserModel user(newID, name, pwd);
	users.insert(pair<string, UserModel>(newID, user));
	FileWriteUserInfo();
	return true;
}
bool PlatformController::GenerateNewCommodity(string name, double pri, int num, string des, string sid)
{
	string newID = GenerateNewID(goods, "M");
	CommodityModel com(newID, name, pri, num, des, sid, GetCurDate(), true, GetCurTime());
	goods.insert(pair<string, CommodityModel>(newID, com));
	FileWriteCommodityInfo();
	return true;
}
bool PlatformController::GenerateNewOrder(string cid, double pri, int num, string sid, string bid)
{
	string newID = GenerateNewID(orders, "T");
	OrderModel od(newID, cid, pri, num, GetCurDate(), sid, bid);
	orders.insert(pair<string, OrderModel>(newID, od));
	FileWriteOrderInfo();
	return true;
}
//File Read and Write
bool PlatformController::FileLoadUserInfo()
{
	fstream fi(userFile, ios::in);
	if (!fi)
	{
		fi.open(userFile, ios::out | ios::app);
		fi.close();
		fi.open(userFile, ios::in);
	}
	string line;
	while (getline(fi, line))
	{
		istringstream ss(line);
		string str;
		UserModel user;
		for (int i = 0; i < 7; i++)
		{
			getline(ss, str, ',');
			switch (i)
			{
			case 0:user.userID = str; break;
			case 1:user.userName = str; break;
			case 2:user.passWord = str; break;
			case 3:user.phoneNumber = str; break;
			case 4:user.address = str; break;
			case 5:user.balance = stod(str); break;
			case 6:user.userState = str == "active" ? true : false; break;
			}
		}
		users[user.userID] = user;
	}
	fi.close();
	return true;
}
bool PlatformController::FileWriteUserInfo()
{
	fstream fo(userFile, ios::out);
	if (!fo)
		return false;
	for (auto& x : users)fo << x.second.userID << ',' << x.second.userName << ',' << x.second.passWord << ',' << x.second.phoneNumber << ',' << x.second.address << ',' << x.second.balance << ',' << ((x.second.userState == true) ? "active" : "inactive") << "\n";
	return true;
}
bool PlatformController::FileLoadCommodityInfo()
{
	fstream fi(commodityFile, ios::in);
	if (!fi)
	{
		fi.open(commodityFile, ios::out | ios::app);
		fi.close();
		fi.open(commodityFile, ios::in);
	}
	string line;
	while (getline(fi, line))
	{
		istringstream ss(line);
		string str;
		CommodityModel com;
		for (int i = 0; i < 9; i++)
		{
			getline(ss, str, ',');
			switch (i)
			{
			case 0:com.commodityID = str; break;
			case 1:com.commodityName = str; break;
			case 2:com.price = stod(str); break;
			case 3:com.number = stoi(str); break;
			case 4:com.description = str; break;
			case 5:com.sellerID = str; break;
			case 6:com.addedDate = str; break;
			case 7:com.state = str == "onAuction" ? true : false; break;
			case 8:com.time = stoll(str); break;
			}
		}
		goods[com.commodityID] = com;
	}
	fi.close();
	return true;
}
bool PlatformController::FileWriteCommodityInfo()
{
	fstream fo(commodityFile, ios::out);
	if (!fo)
		return false;
	for (auto& x : goods)fo << x.second.commodityID << ',' << x.second.commodityName << ',' << x.second.price << ',' << x.second.number << ',' << x.second.description << ',' << x.second.sellerID << ',' << x.second.addedDate << ',' << ((x.second.state == true) ? "onAuction" : "removed") << ',' << x.second.time << "\n";
	return true;
}
bool PlatformController::FileLoadOrderInfo()
{
	fstream fi(orderFile, ios::in);
	if (!fi)
	{
		fi.open(orderFile, ios::out | ios::app);
		fi.close();
		fi.open(orderFile, ios::in);
	}
	string line;
	while (getline(fi, line))
	{
		istringstream ss(line);
		string str;
		OrderModel od;
		for (int i = 0; i < 7; i++)
		{
			getline(ss, str, ',');
			switch (i)
			{
			case 0:od.orderID = str; break;
			case 1:od.commodityID = str; break;
			case 2:od.unitPrice = stod(str); break;
			case 3:od.number = stoi(str); break;
			case 4:od.date = str; break;
			case 5:od.sellerID = str; break;
			case 6:od.buyerID = str; break;
			}
		}
		orders[od.orderID] = od;
	}
	fi.close();
	return true;
}
bool PlatformController::FileWriteOrderInfo()
{
	fstream fo(orderFile, ios::out);
	if (!fo)
		return false;
	for (auto& x : orders)fo << x.second.orderID << ',' << x.second.commodityID << ',' << x.second.unitPrice << ',' << x.second.number << ',' << x.second.date << ',' << x.second.sellerID << ',' << x.second.buyerID << "\n";
	return true;
}
bool PlatformController::FileLoadBidInfo()
{
	fstream fi(bidFile, ios::in);
	if (!fi)
	{
		fi.open(bidFile, ios::out | ios::app);
		fi.close();
		fi.open(bidFile, ios::in);
	}
	string line;
	while (getline(fi, line))
	{
		istringstream ss(line);
		string str;
		UserBidModel bi(0, 0, "", NULL);
		string cid;
		for (int i = 0; i < 5; i++)
		{
			getline(ss, str, ',');
			switch (i)
			{
			case 0:cid = str; break;
			case 1:bi.offer = stod(str); break;
			case 2:bi.number = stoi(str); break;
			case 3:bi.bidUserID = str; break;
			case 4:bi.time = stoll(str); break;
			}
		}
		bidList[cid].push_back(bi);
	}
	fi.close();
	return true;
}
bool PlatformController::FileWriteBidInfo()
{
	fstream fo(bidFile, ios::out);
	if (!fo)
		return false;
	for (auto& list : bidList)
	{
		for (auto& md : list.second)
		{
			fo << list.first << ',' << md.offer << ',' << md.number << ',' << md.bidUserID << ',' << md.time << "\n";
		}
	}
	return true;
}
//Timer
void PlatformController::CreateTimer(uint64_t interval)
{
	timer = Timer<PlatformController>(interval, this, &PlatformController::BidSearchList);
	th = thread(&Timer<PlatformController>::Start, &timer);
	th.detach();
}
void PlatformController::StopTimer()
{
	timer.Stop();
}
void PlatformController::DeleteTimer()
{
	th.~thread();
}
//Common
PlatformController::PlatformController()
{
	conState = stLogout;
	curUserID = "";
	FileLoadUserInfo();
	FileLoadCommodityInfo();
	FileLoadOrderInfo();
	FileLoadBidInfo();
	CreateTimer(1000);
}
PlatformController::~PlatformController()
{
	DeleteTimer();
	FileWriteUserInfo();
	FileWriteCommodityInfo();
	FileWriteOrderInfo();
	FileWriteBidInfo();
}
bool PlatformController::cmp(const UserBidModel& u1, const UserBidModel& u2)
{
	if (u1.offer > u2.offer)
		return true;
	else if (u1.offer == u2.offer)
		return u1.time < u2.time;
	else
		return false;
}
bool PlatformController::Logout()
{
	conState = stLogout;
	curUserID.clear();
	return true;
}
ConState PlatformController::GetConState()
{
	return conState;
}
string PlatformController::GetCurDate()
{
	time_t now = time(NULL);
	tm lt;
	localtime_s(&lt, &now);
	string year = to_string(lt.tm_year + 1900);
	string mon = to_string(lt.tm_mon + 1);
	string day = to_string(lt.tm_mday);
	//format to yyyy-mm-dd
	for (int len = mon.length(); len < 2; len++)
		mon.insert(0, "0");
	for (int len = day.length(); len < 2; len++)
		day.insert(0, "0");
	return year + "-" + mon + "-" + day;
}
time_t PlatformController::GetCurTime()
{
	return time(NULL);
}
//Admin
bool PlatformController::AdminLogin(string adminName, string pwd)
{
	if (adminName == this->adminName && pwd == adminPwd)
	{
		conState = stAdminLogin;
		return true;
	}
	return false;
}
bool PlatformController::AdminGetUserList(map<string, UserModel>& usrs)
{
	if (conState == stAdminLogin)
	{
		usrs = users;
		return true;
	}
	return false;
}
bool PlatformController::AdminGetCommodityList(map<string, CommodityModel>& coms)
{
	if (conState == stAdminLogin)
	{
		coms = goods;
		return true;
	}
	return false;
}
bool PlatformController::AdminGetOrderList(map<string, OrderModel>& ods)
{
	if (conState == stAdminLogin)
	{
		ods = orders;
		return true;
	}
	return false;
}
bool PlatformController::AdminSearchCommodity(string name, map<string, CommodityModel>& coms)
{
	if (conState == stAdminLogin)
	{
		map<string, CommodityModel>::iterator it;
		for (it = goods.begin(); it != goods.end(); it++)
		{
			if (it->second.commodityName == name)
			{
				coms.insert(*it);
			}
		}
		return true;
	}
	return false;
}
bool PlatformController::AdminGetCommodity(string cid, CommodityModel& com)
{
	if (conState == stAdminLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end())
		{
			com = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::AdminGetUser(string uid, UserModel& usr)
{
	if (conState == stAdminLogin)
	{
		map<string, UserModel>::iterator it = users.find(uid);
		if (it != users.end())
		{
			usr = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::AdminGetOrder(string oid, OrderModel& ord)
{
	if (conState == stAdminLogin)
	{
		map<string, OrderModel>::iterator it = orders.find(oid);
		if (it != orders.end())
		{
			ord = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::AdminUpshelfCommodity(string cid)
{
	if (conState == stAdminLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end())
		{
			it->second.state = true;
			FileWriteCommodityInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::AdminDownshelfCommodity(string cid)
{
	if (conState == stAdminLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end())
		{
			it->second.state = false;
			FileWriteCommodityInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::AdminDeactiveUser(string uid)
{
	if (conState == stAdminLogin)
	{
		map<string, UserModel>::iterator it = users.find(uid);
		if (it != users.end())
		{
			it->second.userState = false;
			map<string, CommodityModel>::iterator cit;
			for (cit = goods.begin(); cit != goods.end(); cit++)
			{
				if (cit->second.sellerID == uid)
					cit->second.state = false;
			}
			for (auto& list : bidList)
			{
				vector<UserBidModel>::iterator uit;
				for (uit = list.second.begin(); uit != list.second.end();)
				{
					if (uit->bidUserID == uid)
						uit = list.second.erase(uit);
					else
						uit++;
				}
			}
			FileWriteUserInfo();
			FileWriteCommodityInfo();
			FileWriteBidInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::AdminActiveUser(string uid)
{
	if (conState == stAdminLogin)
	{
		map<string, UserModel>::iterator it = users.find(uid);
		if (it != users.end())
		{
			it->second.userState = true;
			FileWriteUserInfo();
			return true;
		}
	}
	return false;
}
//User
bool PlatformController::UserRegister(string userName, string pwd)
{
	map<string, UserModel>::iterator it;
	for (it = users.begin(); it != users.end(); it++)
	{
		if (userName == it->second.userName)
			return false;
	}
	GenerateNewUser(userName, pwd);
	return true;
}
bool PlatformController::UserLogin(string userName, string pwd)
{
	map<string, UserModel>::iterator it;
	for (it = users.begin(); it != users.end(); it++)
	{
		if (userName == it->second.userName && pwd == it->second.passWord && it->second.userState == true)
		{
			conState = stUserLogin;
			curUserID = it->second.userID;
			return true;
		}
	}
	return false;
}
bool PlatformController::UserGetCurInfo(UserModel& curUser)
{
	if (conState == stUserLogin)
	{
		map<string, UserModel>::iterator it = users.find(curUserID);
		if (it != users.end())
		{
			curUser = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::UserModifyCurInfo(string name, string pwd, string ph, string add, double bal)
{
	if (conState == stUserLogin)
	{
		map<string, UserModel>::iterator it = users.find(curUserID);
		if (it != users.end() && bal >= 0)
		{
			if (!name.empty())
				it->second.userName = name;
			if (!pwd.empty())
				it->second.passWord = pwd;
			if (!ph.empty())
				it->second.phoneNumber = ph;
			if (!add.empty())
				it->second.address = add;
				it->second.balance += bal;
			FileWriteUserInfo();
			return true;
		}
	}
	return false;
}
//Buyer
bool PlatformController::BuyerGetCommodityList(map<string, CommodityModel>& coms)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it;
		for (it = goods.begin(); it != goods.end(); it++)
		{
			if (it->second.state == true)
			{
				coms.insert(*it);
			}
		}
		return true;
	}
	return false;
}
bool PlatformController::BuyerGetHistoryOrderList(map<string, OrderModel>& ods)
{
	if (conState == stUserLogin)
	{
		map<string, OrderModel>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++)
		{
			if (it->second.buyerID == curUserID)
			{
				ods.insert(*it);
			}
		}
		return true;
	}
	return false;
}
bool PlatformController::BuyerGetOrder(string oid, OrderModel& ord)
{
	if (conState == stUserLogin)
	{
		map<string, OrderModel>::iterator it = orders.find(oid);
		if (it != orders.end() && it->second.buyerID == curUserID)
		{
			ord = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::BuyerSearchCommodity(string name, map<string, CommodityModel>& coms)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it;
		for (it = goods.begin(); it != goods.end(); it++)
		{
			if (it->second.state == true && it->second.commodityName == name)
			{
				coms.insert(*it);
			}
		}
		return true;
	}
	return false;
}
bool PlatformController::BuyerGetCommodityDescription(string cid, string& des)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end() && it->second.state == true)
		{
			des = it->second.description;
			return true;
		}
	}
	return false;
}
bool PlatformController::BuyerGetCommodityDetail(string cid, CommodityModel& com)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end() && it->second.state == true)
		{
			com = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::BuyerGetBidList(map<string, vector<UserBidModel>>& bids)
{
	if (conState == stUserLogin)
	{
		map<string, vector<UserBidModel>>::iterator bit;
		vector<UserBidModel>::iterator uit;
		for (bit = bidList.begin(); bit != bidList.end(); bit++)
		{
			for (uit = (*bit).second.begin(); uit != (*bit).second.end(); uit++)
			{
				if ((*uit).bidUserID == curUserID)
				{
					bids[(*bit).first].push_back(*uit);
					break;
				}
			}
		}
	}
	return false;
}
bool PlatformController::BuyerBidCommodity(double offer, string cid, int num)
{
	if (conState == stUserLogin)
	{
		map<string, UserModel>::iterator it = users.find(curUserID);
		map<string, CommodityModel>::iterator cit = goods.find(cid);
		double sum = offer * (double)num;
		if (it != users.end() && cit != goods.end() && cit->second.state == true && sum <= it->second.balance && offer >= cit->second.price)
		{
			UserBidModel bid(offer, num, curUserID, GetCurTime());
			bidList[cid].push_back(bid);
			FileWriteBidInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::BuyerBidCancel(string cid)
{
	if (conState == stUserLogin)
	{
		map<string, UserModel>::iterator it = users.find(curUserID);
		map<string, CommodityModel>::iterator cit = goods.find(cid);
		if (it != users.end() && cit != goods.end() && cit->second.state == true)
		{
			vector<UserBidModel>::iterator bit;
			for (bit = bidList[cid].begin(); bit != bidList[cid].end(); bit++)
			{
				if ((*bit).bidUserID == curUserID)
					break;
			}
			if (bit != bidList[cid].end())
			{
				bidList[cid].erase(bit);
				FileWriteBidInfo();
				return true;
			}
		}
	}
	return false;
}
bool PlatformController::BuyerBidChangeOffer(double offer, string cid, int num)
{
	if (conState == stUserLogin)
	{
		map<string, UserModel>::iterator it = users.find(curUserID);
		map<string, CommodityModel>::iterator cit = goods.find(cid);
		double sum = offer * (double)num;
		if (it != users.end() && cit != goods.end() && cit->second.state == true && sum <= it->second.balance && offer >= cit->second.price)
		{
			vector<UserBidModel>::iterator bit;
			for (bit = bidList[cid].begin(); bit != bidList[cid].end(); bit++)
			{
				if ((*bit).bidUserID == curUserID)
					break;
			}
			if (bit != bidList[cid].end())
			{
				(*bit).offer = offer;
				if (num > 0)
					(*bit).number = num;
				(*bit).time = GetCurTime();
				FileWriteBidInfo();
				return true;
			}
		}
	}
	return false;
}
bool PlatformController::BuyerBuyCommodity(string bid, double money)
{
	map<string, UserModel>::iterator it = users.find(bid);
	if (it != users.end())
	{
		it->second.balance -= money;
		FileWriteUserInfo();
		return true;
	}
	return false;
}

//Seller
bool PlatformController::SellerGetCommodityList(map<string, CommodityModel>& coms)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it;
		for (it = goods.begin(); it != goods.end(); it++)
		{
			if (it->second.sellerID == curUserID)
			{
				coms.insert(*it);
			}
		}
		return true;
	}
	return false;
}
bool PlatformController::SellerGetCommodity(string cid, CommodityModel& com)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end() && it->second.sellerID == curUserID)
		{
			com = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::SellerGetHistoryOrderList(map<string, OrderModel>& ods)
{
	if (conState == stUserLogin)
	{
		map<string, OrderModel>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++)
		{
			if (it->second.sellerID == curUserID)
			{
				ods.insert(*it);
			}
		}
		return true;
	}
	return false;
}
bool PlatformController::SellerGetOrder(string oid, OrderModel& ord)
{
	if (conState == stUserLogin)
	{
		map<string, OrderModel>::iterator it = orders.find(oid);
		if (it != orders.end() && it->second.sellerID == curUserID)
		{
			ord = it->second;
			return true;
		}
	}
	return false;
}
bool PlatformController::SellerReleaseCommodity(string name, double pri, int num, string des)
{
	if (conState == stUserLogin)
	{
		if (pri >= 0 && num >= 0)
		{
			GenerateNewCommodity(name, pri, num, des, curUserID);
			return true;
		}
	}
	return false;
}
bool PlatformController::SellerModifyCommodityInfo(string cid, double pri, string des, int num, string name)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end())
		{
			if (!name.empty())
				it->second.commodityName = name;
			if (pri >= 0)
				it->second.price = pri;
			if (!des.empty())
				it->second.description = des;
			if (num >= 0)
				it->second.number = num;
			FileWriteCommodityInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::SellerDownshelfCommodity(string cid)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end() && it->second.sellerID == curUserID)
		{
			it->second.state = false;
			FileWriteCommodityInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::SellerUpshelfCommodity(string cid)
{
	if (conState == stUserLogin)
	{
		map<string, CommodityModel>::iterator it = goods.find(cid);
		if (it != goods.end() && it->second.sellerID == curUserID)
		{
			it->second.state = true;
			FileWriteCommodityInfo();
			return true;
		}
	}
	return false;
}
bool PlatformController::SellerSoldCommodity(string sid, double money)
{
	map<string, UserModel>::iterator it = users.find(sid);
	if (it != users.end())
	{
		it->second.balance += money;
		FileWriteUserInfo();
		return true;
	}
	return false;
}
//Bid
bool PlatformController::BidCommodity(string cid)
{
	map<string, CommodityModel>::iterator it = goods.find(cid);
	map<string, vector<UserBidModel>>::iterator bit = bidList.find(cid);
	if (it != goods.end() && bit != bidList.end() && it->second.state == true)
	{
		string sid = it->second.sellerID;
		sort(bit->second.begin(), bit->second.end(), cmp);
		vector<UserBidModel>::iterator uit = bit->second.begin();
		while (uit != bit->second.end())
		{
			string bid = uit->bidUserID;
			int cnum = it->second.number;
			int unum = uit->number;			
			if (users[bid].balance >= (unum * uit->offer))
			{
				if (unum >= cnum)
				{			
					double sumPrice = uit->offer * cnum;
					BuyerBuyCommodity(bid, sumPrice);
					SellerSoldCommodity(sid, sumPrice);
					GenerateNewOrder(cid, uit->offer, cnum, sid, bid);
					it->second.number = 0;
					FileWriteUserInfo();
					FileWriteCommodityInfo();
					FileWriteOrderInfo();
					return true;
				}
				else
				{
					double sumPrice = uit->offer * unum;
					BuyerBuyCommodity(bid, sumPrice);
					SellerSoldCommodity(sid, sumPrice);
					GenerateNewOrder(cid, uit->offer, unum, sid, bid);
					it->second.number -= unum;
					FileWriteUserInfo();
					FileWriteCommodityInfo();
					FileWriteOrderInfo();
					uit++;
				}
			}
			else
			{
				uit = bit->second.erase(uit);
			}
		}
	}
	return false;
}
void PlatformController::BidSearchList()
{
	map<string, vector<UserBidModel>>::iterator bit;
	for (bit = bidList.begin(); bit != bidList.end();)
	{
		string cid = bit->first;
		map<string, CommodityModel>::iterator cit = goods.find(cid);
		if (cit != goods.end() && time(NULL) - cit->second.time >= span)
		{
			bool success = BidCommodity(cid);
			if (success)
			{
				bit = bidList.erase(bit);
			}
			else
			{
				if (!cit->second.state)
					bit = bidList.erase(bit);
				else
				{
					cit->second.time = time(NULL);
					bit->second.clear();
					bit++;
				}
			}
			FileWriteBidInfo();
		}
	}
}
//Test
void PlatformController::Test()
{
	cout << "Tick!" << endl;
}