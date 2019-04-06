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
void View:: mainLobby(char* username)
{
// noecho();
	initscr();
	clear();
	refresh();
        int yMax,xMax;
	//,start_y,start_x;
        getmaxyx(stdscr,yMax,xMax);
        WINDOW * active = newwin(23,xMax-90,yMax-30,1);
        WINDOW * sideChats = newwin(23,xMax-90,yMax-30,88);
        WINDOW * centerChat = newwin(29,xMax-85,yMax-30,42);
        WINDOW * Panel1 = newwin(6,xMax-92,yMax-6,1);
        WINDOW * Panel2 = newwin(6,xMax-92,yMax-6,89);
        wborder(active,(int)' ',(int)'#',(int)' ',(int)' ',(int)'#',(int)'#',(int)'#',(int)'#');
        wborder(sideChats,(int)'#',(int)' ',(int)' ',(int)' ',(int)'#',(int)'#',(int)'#',(int)'#');
        wborder(centerChat,(int)' ',(int)' ',(int)'#',(int)' ',(int)'#',(int)'#',(int)'#',(int)'#');


        char  usernam[100];
       // char  password[100];

        box(Panel1,0,0);
        box(Panel2,0,0);
	//string userc(username);
        refresh();
                     strcpy(usernam,username);
       			     mvwprintw(centerChat,1,22,"Home");
        mvwprintw(active,1,1,"Active Friends");
        mvwprintw(sideChats,1,2,"Chats");

        string choices1[6]={"aa- DM","bb- Chat","cc- Create Chat","dd- logout","ee- FILLER","ff- FILLER"};
        string choices2[6]={"gg- Find Chat","hh- FILLER","ii- FILLER","jj- FILLER","kk- FILLER","ll- FILLER"};
        int choice;
        //int highlight=0;
        mvwprintw(Panel1,1,1,"Navigate:");
        int two=2;
        int watch=0;
        int column=1;
                for(int i=0;i<6;i++)//displays choices on window
                {
                        if((i%3==0)&&(i!=0))
                        {
                                column+=17;

                                two=-1;
                                if((watch%3==0)&&(watch!=0))
                                        two=-200;
                                watch=0;
                        }
                        mvwprintw(Panel1,i+two,column,choices1[i].c_str());
                }
                column=1;
                watch=0;
                                                        two=2;
                for(int i=0;i<6;i++)//displays choices on window
                {
                        if((i%3==0)&&(i!=0))
                        {
                                column+=17;
                                two=-1;
                                if((watch%3==0)&&(watch!=0))
                                        two=-200;
                                watch=0;
                        }
                        mvwprintw(Panel2,i+two,column,choices2[i].c_str());
                }


//use this as a refernce to plug info into ncurses display
/*int i=0;
 * int LimitOfWindow=10;
 * while(i<friendslist.size())
 {
 //display info to active window
 i++;
                        mvwprintw(active,i+2,1,friendslist[i].name.c_str());
 
 }

 */
	refresh();
   	wrefresh(centerChat);
        wrefresh(sideChats);
        wrefresh(active);
        wrefresh(Panel1);
        wrefresh(Panel2);
        keypad(Panel1,true);

        keypad(Panel2,true);
        int p1choice=-99;
        int p2choice=-99;

        noecho();
        while(1)
        {
        p1choice=wgetch(Panel1);
        p2choice=wgetch(Panel2);
        choice=p1choice;
        choice=p2choice;


                switch(choice)
                {

                        case 97 ://aa

                                break;
                        case 98 ://bb

                                break;
                        case 99 ://cc

				  break;
                        case 100 ://dd

                                break;
                        case 101 ://ee

                                break;
                        case 102 ://ff

                                break;
                        case 103 ://gg

                                break;
                        case 104 ://hh

                                break;
                        case 105 ://ii

                                break;
                        case 106 ://jj

                                break;
                        case 107 ://kk

                                break;
                        case 108 ://ll

                                break;
                        default:
			   	 break;

                }

                if (choice==100)
                        break;
        }
	endwin();

}

string View:: help()
{
	string rules="General Rules\n1. Be Nice \n2.Treat people how you want to be treated\n3.Have fun.\n by signing up you agree to these terms.";
	return rules;
}
void View:: signup(char * username,char *password)
{
//mainLobby(username);
//register user into system
}
void View:: signin(char* username,char *password)
{
//mainLobby(username);
//log user into system
}
void View:: loginScreen()
{

  int yMax,xMax;
  //,start_y,start_x;
        getmaxyx(stdscr,yMax,xMax);
        WINDOW * me = newwin(5,xMax-50,yMax-24,26);
        //WINDOW * mee = newwin(3,xMax-20,yMax-20,10);
        WINDOW * labelmee = newwin(3,xMax-20,yMax-17,10);
        WINDOW * mee = newwin(3,xMax-40,yMax-15,10);
        WINDOW * meen = newwin(3,xMax-40,yMax-10,10);//length,left right, up down, width
        WINDOW * labelmeen = newwin(3,xMax-40,yMax-12,10);
        //box(me,0,0);
        WINDOW * Rememberme = newwin(8,xMax-6,yMax-6,5);
        mvwprintw(me,1,1,"Sign in");
        mvwprintw(labelmee,1,0," Enter Username:");
        mvwprintw(labelmeen,1,0," Enter Password:");

        char  username[100];
        char  password[100];

        box(mee,0,0);
        box(meen,0,0);
        box(Rememberme,0,0);

        refresh();
        wrefresh(me);
        wrefresh(labelmee);
        wrefresh(labelmeen);
        wrefresh(mee);
        wrefresh(meen);

	echo();
        mvwgetstr(mee,1,1,username);
	noecho();
        mvwgetstr(meen,1,1,password);
                //wclear(mee);
        /*while (strcmp(username,"go")!=0)//this will be modified and used for when user inputs incorrect info 
        {
                mvwprintw(labelmee,1,0,"Enter Username: account does not exsist.Please enter info correctly");
                memset (username,' ',sizeof(username));
                memset (password,' ',sizeof(password));
                werase(mee);
                werase(meen);
                box(mee,0,0);
                box(meen,0,0);
                wrefresh(labelmee);
                wrefresh(labelmeen);
                wrefresh(mee);
                wrefresh(meen);
                mvwgetstr(mee,1,1,username);
             mvwgetstr(meen,1,1,password);
        }
*/
//      refresh();

        wrefresh(Rememberme);
        keypad(Rememberme,true);
        string choices[2]={"Yes","No"};
        int choice;
        int highlight=0;
                                mvwprintw(Rememberme,1,1,"Rememeber Me:");
        while(1)
        {
                for(int i=0;i<2;i++)
                {

                        if (i==highlight)
                                wattron(Rememberme,A_REVERSE);
                                mvwprintw(Rememberme,i+2,1,choices[i].c_str());
                                wattroff(Rememberme,A_REVERSE);
                }
                        choice =wgetch(Rememberme);
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
	 string Remember = choices[highlight];
	//here input code accept whether the user wants to be remembered or not.
	signin(username,password);

}
void View:: signUpScreen()
{
	 int yMax,xMax;
	 //start_y,start_x;
        getmaxyx(stdscr,yMax,xMax);
        WINDOW * me = newwin(5,xMax-50,yMax-24,26);
        //WINDOW * mee = newwin(3,xMax-20,yMax-20,10);
        WINDOW * labelmee = newwin(3,xMax-20,yMax-17,10);
        WINDOW * labelmeen = newwin(3,xMax-40,yMax-12,10);
        WINDOW * mee = newwin(3,xMax-40,yMax-15,10);
        WINDOW * meen = newwin(3,xMax-40,yMax-10,10);//length,left right, up down, width
	WINDOW * Grules = newwin(8,xMax-6,yMax-6,5);
	

        mvwprintw(me,1,1,"Sign Up");
        mvwprintw(labelmee,1,0," Enter Username:");
        mvwprintw(labelmeen,1,0," Enter Password:");
        char  username[100];
        char  password[100];

        box(mee,0,0);
        box(meen,0,0);


        mvwprintw(Grules,1,1,help().c_str());//display general rules on sign up screen
        box(Grules,0,0);
        wrefresh(Grules);

        refresh();
        wrefresh(me);
	wrefresh(labelmee);
        wrefresh(labelmeen);
        wrefresh(mee);
        wrefresh(meen);
	echo();
        mvwgetstr(mee,1,1,username);
	noecho();
        //currently testing, trying to clear username array 
	/*while (strcmp(username, "go")!=0)//this will be modified and used for when a user enters in a username that has already been taken
        {
                mvwprintw(labelmee,1,0," Enter a different user name this has already");
	        memset (username,' ',sizeof(username));
                werase(mee);
                box(mee,0,0);
                wrefresh(labelmee);
                wrefresh(mee);
                mvwgetstr(mee,1,1,username);
	
	}*/
        
	mvwgetstr(meen,1,1,password);
	//might add some testing based on if we care about how secure the passwords are
	signup(username,password);
}

void View:: Welcome()
{
	initscr();
	noecho();
	//cbreak();
	int yMax,xMax;
	//,start_y,start_x;
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

//printw("You chose %s",choices[highlight].c_str());
string next = choices[highlight];
clear();
refresh();
if (next == choices[0])
signUpScreen();
else 
loginScreen();

refresh();
endwin();

//erase();
}


void View:: refreshStatus(){}
int main(int argc, char*argv[])
{
char name[100]={"apple"};
View v;
v.Welcome();
v.mainLobby(name);
getch();


}
