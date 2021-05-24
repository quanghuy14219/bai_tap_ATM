#pragma once
#include <windows.h>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class My_ATM {
public:
	void dangky();
	void dangnhap();
	void nhapmk(string username);
	void gd0();
	void gd1();
	void gdadmin();
	void unlocktk(string username);
	void gdquit();
	void gduser(string username);
	void naptien(string& username, string& PIN, long long& balance);
	void congtienvaotk(string& username, string& PIN, long long& balance, long long menhgia);
	void ruttien(string& username, string& PIN, long long& balance);
	int sotorutra(long long& money, long long menhgia, int& sotocosan);
	void chuyenkhoan(string&  username, string& PIN, long long& balance);
	void xemlichsugd(string& username);
	string thoidiem();
	long long sotonow(long long menhgia);
	void thaydoisoto(long long menhgia, long long soto);
	void doimatkhau(string& username, string& PIN, long long& balance);
};
