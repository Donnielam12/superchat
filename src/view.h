#ifndef VIEW
#define VIEW
#include<iostream>
#include<vector>
using namespace std;

class View
{
	public:
		bool Status;
		View();
		void scrollBar();
		string keyboardShortcut();
		void fileDialog();
		void colorText();
		string fonts();
		void  mainLobby(char *username);
		void loginScreen();
		void signUpScreen();
		string help();
		void Welcome();
		void signup(char * username,char *password);
		void signin(char * username,char *password);
		void refreshStatus();
};

#endif
