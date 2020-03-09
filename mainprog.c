#include<ncurses.h>
#include<string.h>
#include "projectheader.h"
void main()
{
	int choice,game;
	WINDOW *w;
	initscr();
	noecho();
	curs_set(0);
	int r=1;
	
	keypad(stdscr,TRUE);
	start_color();
	
	start_game();

	choice = chosen_choice();
here:	while(r)
	{
		switch(choice)
		{
			case 1:
				Demo_game();
				choice=chosen_choice();
				goto here;
				break;
			case 2:
				game=play_demo();
				choice=chosen_choice();
				goto here;
				break;
			case 3:
				w=create(10,10);
				game=play_game();
				if(game==0)
				{
					mvwprintw(w,25,2,"the game is over");
					refresh();
					wrefresh(w);
				}
				else if(game==1)
				{
					mvwprintw(w,25,2,"you won the game");
					refresh();
					wrefresh(w);
				}
				//getch();
				delwin(w);
				choice=chosen_choice();		
				goto here;
				break;
			case 4:
				display_score();
				getch();
				choice=chosen_choice();			
				goto here;
				break;
			case 5:
				delwin(w);
				r=0;
				goto here;
				break;
			case 27: 
				delwin(w);
				r=0;
				goto here;
				break;
		}
	}
	delwin(w);
	endwin();
}
