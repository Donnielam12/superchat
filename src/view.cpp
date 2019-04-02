#include<iostream>
#include"view.h"
#include<ncurses.h>
using namespace std;

View::View(){}
void View::scrollBar(){}
string View::keyboardShortcut(){}
void View:: fileDialog(){}
void View:: colorText(){}
string View:: fonts(){}
void View:: loginScreen(){}
void View:: signUpScreen()
{

	initscr();
	noecho();
	int yMax,xMax,start_y,start_x;
	getmaxyx(stdscr,yMax,xMax);
	WINDOW * me = newwin(10,xMax-50,yMax-20,5);
	box(me,0,0);
	mvwprintw(me,1,1,"Sign Up");
	refresh();
	wrefresh(me);


}
void View:: Welcome()
{
	initscr();
	noecho();
	cbreak();
	int yMax,xMax,start_y,start_x;
	getmaxyx(stdscr,yMax,xMax);
	WINDOW * menu = newwin(10,xMax-50,yMax-20,5);
	//box(menu,0,0);
	char space= '*';
	char ci= ' ';
	wborder(menu,(int)ci,(int)ci,(int)space,(int)space,(int)'#',(int)'#',(int)'#',(int)'#');
	
	refresh();
	wrefresh(menu);
	keypad(menu,true);
	string choices[2]={"SignUp","SignIn"};
	int choice;
	int highlight=0;
	while(1)
	{
		for(int i=0;i<2;i++)
		{

			if (i==highlight)
				wattron(menu,A_REVERSE);
			mvwprintw(menu,i+1,1,choices[i].c_str());
			wattroff(menu,A_REVERSE);
		}
			choice =wgetch(menu);
			switch(choice)
			{
				case KEY_UP:
				highlight--;
				if(highlight== -1)
					highlight=0;
				break;
				case KEY_DOWN:
					highlight++;
					if(highlight== 2)
						highlight=1;
					break;
				default:
					break;
	
			}	
		if(choice==10)//10 means that the user clicked enter.
		break;
}

printw("You chose %s",choices[highlight].c_str());
string next = choices[highlight];
if (next == choices[0])
signUpScreen();
else 
loginScreen();

getch();
endwin();

}

string View:: help(){}
void View:: signup(){}
void View:: signin(){}
void View:: refreshStatus(){}
int main(int argc, char*argv[])
{
View v;
v.Welcome();


}
