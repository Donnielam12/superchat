#ifndef CON
#define CON
#include<iostream>
#include<srting>
#include<vector>
using namespace std;


class Controller
{
	public:	
		View v;
		vector<user>User;
		vector<lobby>lobby;

		Controller::Controller()
		int leaveLobby();
		int createLobby();
		int Logout();
		int kick();
		int checkInactivity(string x);
		int deleteLobby();
		int addAdmin();
		int checkStatus(string x);
		string lobbySearch();
		string checkExisitingLobby(string x);
		string rememberMe(string x);
};                  

#endif
