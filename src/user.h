#ifndef USE
#define USE
#include<iostream>
#include<string>
#include<vector>
#include"controller.h"
using namespace std;


class User:public Controller
{

	public:
		string name;
		int UniqueID;
		vector<string>Lobbyjoined;
		vector<string>mutedList;
		vector<string>friendList; 
		User();
		int muted();
		string sendFiles();
		string sendMessage();
};



#endif
