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
		void loginScreen();
		void signUpScreen();
		string help();
		void signup();
		void signin();
		void refreshStatus();
};

#endif
