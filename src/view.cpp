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
void View:: Welcome()
{
	initscr();
	noecho();
	int yMax,xMax,start_y,start_x;
	getmaxyx(stdscr,yMax,xMax);
	WINDOW * menu = newwin(5,xMax-12,yMax-8,5);
	box(menu,0,0);
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
			{
				wattron(menu,A_REVERSE);
				mvwprintw(menu,i+1,1,choices[i].c_str());
				wattroff(menu, A_REVERSE);
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

	
}
			if(choice==10)//10 means that the user clicked enter.
				break;



}
printw("You chose %s",choices[highlight].c_str());
getch();
endwin();

}
void View:: signUpScreen(){}
string View:: help(){}
void View:: signup(){}
void View:: signin(){}
void View:: refreshStatus(){}
int main(int argc, char*argv[])
{
View v;
v.Welcome();


}
