#ifndef LOB
#define LOB

#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Lobby: publc Controller
{
	public:
		vector<string> admin;
		vector<string> messages;
		vector<string> timeStamp;
		vector<string> rules;
		vector<string> ban;
		int limit;
		string UniqueID;
		Lobby();
		int createPoll();
		int ban();
		string sendMessage();
		string sendFiles();
		string timeStamp();                          
		

};
#endif
