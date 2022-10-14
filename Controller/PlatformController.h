#pragma once
#include "../Global.h"
#include "../Model/CommodityModel.h"
#include "../Model/UserModel.h"
#include "../Model/UserBidModel.h"
#include "../Model/OrderModel.h"
#include "../Model/Timer.h"

enum ConState { stLogout, stUserLogin, stAdminLogin };

class PlatformController
{
private:
	const string adminName = "admin";
	const string adminPwd = "123";
	const string userFile = "user.txt";
	const string commodityFile = "commodity.txt";
	const string orderFile = "order.txt";
	const string bidFile = "bidList.txt";
	const int64_t span = 60;
	ConState conState;
	string curUserID;
	Timer<PlatformController> timer;
	thread th;
	map<string, CommodityModel> goods;
	map<string, UserModel> users;
	map<string, OrderModel> orders;
	map<string, vector<UserBidModel>> bidList;

	//Generate new id, user, commodity and order
	template <class Tmap>
	string GenerateNewID(Tmap mp, string type);
	bool GenerateNewUser(string name, string pwd);
	bool GenerateNewCommodity(string name, double pri, int num, string des, string sid);
	bool GenerateNewOrder(string cid, double pri, int num, string sid, string bid);
	//File Read and Write
	bool FileLoadUserInfo();
	bool FileWriteUserInfo();
	bool FileLoadCommodityInfo();
	bool FileWriteCommodityInfo();
	bool FileLoadOrderInfo();
	bool FileWriteOrderInfo();
	bool FileLoadBidInfo();
	bool FileWriteBidInfo();
public:
	//Common
	PlatformController();
	~PlatformController();
	static bool cmp(const UserBidModel& u1, const UserBidModel& u2);
	bool Logout();
	ConState GetConState();
	string GetCurDate();
	time_t GetCurTime();
	//Timer
	void CreateTimer(uint64_t interval);
	void StopTimer();
	void DeleteTimer();
	//Admin
	bool AdminLogin(string adminName, string pwd);
	bool AdminGetUserList(map<string, UserModel>& usrs);
	bool AdminGetCommodityList(map<string, CommodityModel>& coms);
	bool AdminGetOrderList(map<string, OrderModel>& ods);
	bool AdminSearchCommodity(string name, map<string, CommodityModel>& coms);
	bool AdminGetCommodity(string cid, CommodityModel& com);
	bool AdminGetUser(string uid, UserModel& usr);
	bool AdminDownshelfCommodity(string cid);
	bool AdminDeactiveUser(string uid);
	//User
	bool UserRegister(string userName, string pwd);
	bool UserLogin(string userName, string pwd);
	bool UserGetCurInfo(UserModel& curUser);
	bool UserModifyCurInfo(string name = "", string pwd = "", string ph = "", string add = "", double bal = 0);
	//Buyer
	bool BuyerGetCommodityList(map<string, CommodityModel>& coms);
	bool BuyerGetHistoryOrderList(map<string, OrderModel>& ods);
	bool BuyerSearchCommodity(string name, map<string, CommodityModel>& coms);
	bool BuyerGetCommodityDescription(string cid, string& des);
	bool BuyerGetCommodityDetail(string cid, CommodityModel& com);
	bool BuyerBidCommodity(double offer, string cid, int num);
	bool BuyerBuyCommodity(string bid, double money);
	//Seller
	bool SellerGetCommodityList(map<string, CommodityModel>& coms);
	bool SellerGetCommodity(string cid, CommodityModel& com);
	bool SellerGetHistoryOrderList(map<string, OrderModel>& ods);
	bool SellerReleaseCommodity(string name, double pri, int num, string des);
	bool SellerModifyCommodityInfo(string cid, double pri = -1, string des = "", int num = -1, string name = "");
	bool SellerDownshelfCommodity(string cid);
	bool SellerUpshelfCommodity(string cid);
	bool SellerSoldCommodity(string sid, double money);
	//Bid
	bool BidCommodity(string cid);
	void BidSearchList();
	//Test
	void Test();
};