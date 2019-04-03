#include<iostream>
#include"view.h"
#include<ncurses.h>
#include<string.h>
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
	 int yMax,xMax,start_y,start_x;
        getmaxyx(stdscr,yMax,xMax);
        WINDOW * me = newwin(5,xMax-50,yMax-24,26);
        //WINDOW * mee = newwin(3,xMax-20,yMax-20,10);
        WINDOW * labelmee = newwin(3,xMax-20,yMax-17,10);
        WINDOW * labelmeen = newwin(3,xMax-40,yMax-12,10);
        WINDOW * mee = newwin(3,xMax-40,yMax-15,10);
        WINDOW * meen = newwin(3,xMax-40,yMax-10,10);//length,left right, up down, width
        //box(me,0,0);

        mvwprintw(me,1,1,"Sign Up");
        mvwprintw(labelmee,1,0," Enter Username:");
        mvwprintw(labelmeen,1,0," Enter Password:");
        char  username[100];
        char  password[100];

        box(mee,0,0);
        box(meen,0,0);

        refresh();
        wrefresh(me);
 wrefresh(labelmee);
        wrefresh(labelmeen);
        wrefresh(mee);
        wrefresh(meen);

        mvwgetstr(mee,1,1,username);
        while (username != "go")//this will be modified and used for when a user enters in a username that has already been taken
        {
                mvwprintw(labelmee,1,0," Enter a different user name this has already");
                wrefresh(labelmee);
                printw("username: %s",username);
                memset (username,0,sizeof(username));

                mvwgetstr(mee,1,1,username);
        }
        mvwgetstr(meen,1,1,password);

        getch();
        endwin();
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
clear();
refresh();
if (next == choices[0])
signUpScreen();
else 
loginScreen();

getch();
refresh();

//erase();
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
