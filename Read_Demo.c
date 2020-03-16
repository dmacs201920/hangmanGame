#include "projectheader.h"

//TO show the demo of the game//
// written by Sushil 173247
void Demo_game()
{
    WINDOW *w;
    w=create(10,10);
    char c;

    mvwprintw(w,1,1,"start");
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"_____");
    mvwprintw(w,4,1,"Here answer is mango");
    mvwprintw(w,5,1,"suppose user  enters 'N'");
    game_zero(w);
    mvwprintw(w,6,1,"Word:_ _ N _ _");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"suppose user  enters 'O'");
    game_zero(w);
    mvwprintw(w,4,1,"Word:_ _ N _ O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"suppose user  enters 'K'");
    mvwprintw(w,4,1,"Wrong Letter");
    game_one(w);
    mvwprintw(w,5,1,"_ _ N _ O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"Third  letter:");
    mvwprintw(w,4,1,"suppose user  enters 'y'");
    mvwprintw(w,5,1,"Wrong Letter");
    game_two(w);
    mvwprintw(w,6,1,"Word:_ _ N _ O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"Third  letter:");
    mvwprintw(w,4,1,"suppose user  enters 'R'");
    mvwprintw(w,5,1,"Wrong Letter");
    game_three(w);
    mvwprintw(w,6,1,"Word:_ _ N _ O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"Third  letter:");
    mvwprintw(w,4,1,"suppose user  enters 'G'");
    game_three(w);
    mvwprintw(w,5,1,"Word:_ _ N G O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"fourth  letter:");
    mvwprintw(w,4,1,"suppose user  enters 'T'");
    mvwprintw(w,5,1,"Wrong Letter");
    game_four(w);
    mvwprintw(w,6,1,"Word:_ _ N G O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);		
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"fourth  letter:");
    mvwprintw(w,4,1,"suppose user  enters 'A'");
    game_four(w);
    mvwprintw(w,5,1,"Word:_ A N G O");
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);	
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"fifth letter:");
    mvwprintw(w,4,1,"suppose user  enters 'D'");
    mvwprintw(w,5,1,"Wrong Letter");
    game_five(w);
    mvwprintw(w,6,1,"Word:_ A N G O");
    mvwprintw(w,7,6,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();
    wclear(w);
    if(c==27)
        goto here;
    delwin(w);

    w=create(10,10);
    mvwprintw(w,14,8,"press ESC to go back to the menu");
    mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
    mvwprintw(w,3,1,"fifth letter:");
    mvwprintw(w,4,1,"suppose user  enters 'H'");
    mvwprintw(w,5,1,"Wrong Letter");
    game_over(w);
    mvwprintw(w,7,1,"press ENTER");
    refresh();
    wrefresh(w);
    c=getch();	
    wclear(w);
    if(c==27)
        goto here;
here:	delwin(w);
        keypad(stdscr,TRUE);	
}
