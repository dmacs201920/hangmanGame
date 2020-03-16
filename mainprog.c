#include<ncurses.h>
#include<string.h>
#include "projectheader.h"
void main()
{
    int choice,game;
    WINDOW *w; //defining the window
    initscr();//initiliazing the screen
    noecho();//doesnt allow the user to see what is being entered 
    curs_set(0);//makes the cursor invisible on the screen
    int r=1;
    keypad(stdscr,TRUE);//function(in ncurses.h) which allows the programer to ue the various keys in the keyboard .eg upper arrow ,lover arrow,etc. 
    start_color();//starts the usuage of the attributes of the color
    start_game();
    choice = chosen_choice();//calling the function to print the main menu and then initialise the option the user has selected
here:	while(r)
        {
            switch(choice)
            {
                case 1://if the user selects the read demo option in the menu
                    Demo_game();
                    choice=chosen_choice();
                    goto here;
                    break;
                case 2://if the user wants to play the demo of the game 
                    game=play_demo();
                    choice=chosen_choice();
                    game=play_demo();
                    choice=chosen_choice();
                    goto here;
                    break;
                case 3://if the user wants to play the game 
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
                    delwin(w);
                    choice=chosen_choice();		
                    goto here;
                    break;
                case 4://if the user wants to see the previous players details 
                    display_score();
                    choice=chosen_choice();			
                    goto here;
                    break;
                case 5://if the user wants to exit the game
                case 27: 
                    delwin(w);
                    r=0;
                    goto here;
                    break;
            }
        }
        delwin(w);//deletes the window if it has not been deleted before
        endwin();//ending the ncurses mode
}
