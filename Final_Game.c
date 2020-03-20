#include "projectheader.h"
extern char *yes_no[];
extern int yes;


//function to start the last stage of the game 
// written by Sushil 173247 then modified by Anirudh 173232

void print_time(WINDOW *w,int h)
{	
    int x,i;
    x=30;
    char *item=malloc(200);
    for(i=0;i<yes;i++)
    {
        wattron(w,COLOR_PAIR(2));
        mvwprintw(w,14,20,"This level can decrease your score drastically");
        mvwprintw(w,15,20,"WOULD YOU LIKE TO CONTINUE?");

        sprintf(item,"%s",yes_no[i]);
        if(h==i+1)
        {
            wattron(w,A_STANDOUT);
            mvwprintw(w,i+18,x,"%s",yes_no[i]);
            wattroff(w,A_STANDOUT);
        }
        else
            mvwprintw(w,i+18,x,"%s",yes_no[i]);
        wattroff(w,COLOR_PAIR(2));
    }
    refresh();
    wrefresh(w);
}

//function to ask the user if he really wants to go into the game
// written by Sushil 173247 then modified by Anirudh 173232
int chosen_time()
{
    WINDOW *wi;
    wi=create(10,10);
    int highlight=1,c,y,x;
    print_time(wi,highlight);
    while(1)
    {		
        c=getch();
        switch(c)
        {
            case KEY_UP:
                if(highlight==1)
                    highlight=yes;
                else 
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight==yes)
                    highlight=1;
                else 
                    ++highlight;
                break;
            case 10:
                refresh();
                wrefresh(wi);
                delwin(wi);
                refresh();
                return highlight;
                break;

                return highlight;
                break;
        }
        print_time(wi,highlight);
    }
    refresh();
    wrefresh(wi);
    delwin(wi);

}

//function to start the last stage of the game
// written by Sushil 173247 then modified by Anirudh 173232
int level_time()
{ 
    int i=5,j=5,t=10,x;
    WINDOW *w;
next1: 
    w=create(10,10);
    mvwprintw(w,15,35,": GENERAL RULES :");
    mvwprintw(w,17,25,"WRONG CHOICE          RIGHT CHOICE ");
    mvwprintw(w,19,25,"SCORE=SCORE-50       SCORE=SCORE+100 ");
    mvwprintw(w,23,20,"PLEASE WAIT");
    if(t%2)
        mvwprintw(w,23,32,"....");
    else if(t%3)
        mvwprintw(w,23,32,"........");
    refresh();
    wrefresh(w);
    wclear(w);
    sleep(1);
    delwin(w);
    t--;
    if(t>0)
        goto next1;
    x=chosen_time();
    if(x==1)
        return x;

next:
    wattron(w,COLOR_PAIR(4));
    w=create(10,10);
    mvwprintw(w,14,15,"WELCOME TO THE FINAL LEVEL");     
    mvwprintw(w,17,16,"%d  %d  %d  %d  %d  %d %d",j+1,j,j+3,j,j+5,j,j+7);
    mvwprintw(w,10,38,"\\");
    mvwprintw(w,10,39,"O/");
    mvwprintw(w,11,39,"|");
    mvwprintw(w,12,40,"\\ ");
    mvwprintw(w,12,38,"/");
    wattroff(w,COLOR_PAIR(4));
    j--; 
    refresh();
    wrefresh(w);
    wclear(w);
    sleep(1);
    delwin(w);
    if(j>0)
        goto next;
    w=create(10,10);
    wattron(w,COLOR_PAIR(3));
    mvwprintw(w,15,30,"::::::All THE BEST::::::::::");
    wattroff(w,COLOR_PAIR(3));
    wrefresh(w);
    wclear(w);
    getch();
    delwin(w);
    return x;
}


//funcion to keep track of the entered letter and keep track of the number of mistakes made for the level time trial
// written by Sushil 173247 then modified by Anirudh 173232
int track_time(char word[],char hint[],int *score,int *chances)
{
    int check,d=0;
    char wrong[6];
    char c;
    int l=strlen(word);
    char tempword[20];
    int pos;
    char forming[20];
    int i,j;

    strcpy(tempword,word);	
    WINDOW *wi;
    wi=create(10,10);
    wattron(wi,COLOR_PAIR(4));
    wattron(wi,A_REVERSE);
    mvwprintw(wi,1,36,"HANGMAN!!!");
    wattroff(wi,A_REVERSE);
    wattroff(wi,COLOR_PAIR(4));
    wattron(wi,COLOR_PAIR(3));
    mvwprintw(wi,1,60,"LEVEL::");
    wattroff(wi,COLOR_PAIR(3));
    wattron(wi,COLOR_PAIR(4));
    mvwprintw(wi,2,70,"SCORE::");
    mvwprintw(wi,2,79,"%d",(*score));
    wattroff(wi,COLOR_PAIR(4));
    wattron(wi,COLOR_PAIR(3));
    mvwprintw(wi,4,2,"HINT::");
    mvwprintw(wi,4,8,"%s",hint);
    wattroff(wi,COLOR_PAIR(3));
    wattron(wi,COLOR_PAIR(2));
    mvwprintw(wi,1,69,"FINAL");
    mvwprintw(wi,3,79,"%d",6-(*chances));
    mvwprintw(wi,3,63,"CHANCES LEFT::");
    wattroff(wi,COLOR_PAIR(2));

    for (i=0;i<l;i++)
        forming[i]='_';
    forming[i]='\0';

    mvwprintw(wi,6,2,"please enter letter:");
    refresh();
    wrefresh(wi);

    while((*chances)!=6 && strlen(word)!=0)
    {
        wattron(wi,COLOR_PAIR(4));
        wattron(wi,A_REVERSE);
        mvwprintw(wi,1,36,"HANGMAN!!!");
        wattroff(wi,A_REVERSE);
        wattroff(wi,COLOR_PAIR(4));
        wattron(wi,COLOR_PAIR(3));
        mvwprintw(wi,1,60,"LEVEL::");
        mvwprintw(wi,4,2,"HINT::");
        mvwprintw(wi,4,8,"%s",hint);
        wattroff(wi,COLOR_PAIR(3));
        wattron(wi,COLOR_PAIR(4));
        mvwprintw(wi,2,70,"SCORE::");
        mvwprintw(wi,2,79,"%d",(*score));
        mvwprintw(wi,17,2,"FORMING WORD");
        wattroff(wi,COLOR_PAIR(4));
        wattron(wi,COLOR_PAIR(2));
        mvwprintw(wi,3,79,"%d",6-(*chances));
        mvwprintw(wi,3,63,"CHANCES LEFT::");
        mvwprintw(wi,1,69,"FINAL");
        mvwprintw(wi,14,2,"WRONG CHOICES");
        wattroff(wi,COLOR_PAIR(2));
        mvwprintw(wi,6,2,"please enter letter:");
        c=getch();
        check=checkletter(c,word);
        if(check==0)
        { 
            (*score)=(*score)-50;
            (*chances)+=1;
            wrong[d]=c;
            wrong[d+1]='\0';
            ++d;
            Display_man(wi,(*chances));
            wattron(wi,COLOR_PAIR(2));
            mvwprintw(wi,3,79,"%d",6-(*chances));
            wattroff(wi,COLOR_PAIR(2));
            for (j=0;j<strlen(forming);j++)
            {
                wattron(wi,COLOR_PAIR(4));
                mvwprintw(wi,18,3+j,"%c",forming[j]);
                wattroff(wi,COLOR_PAIR(4));
            }
            for(i=0;i<strlen(wrong);i++)
            {
                wattron(wi,COLOR_PAIR(2));
                mvwprintw(wi,14,2,"WRONG CHOICES");
                mvwprintw(wi,15,(2+i),"%c",wrong[i]);
                wattroff(wi,COLOR_PAIR(2));
                wattron(wi,COLOR_PAIR(4));
                mvwprintw(wi,2,79,"%d",(*score));
                wattroff(wi,COLOR_PAIR(4));
            }
        }
        else if(check!=0 && check!=27)
        {
            (*score)=(*score)+100;
            Display_man(wi,(*chances));
            wattron(wi,COLOR_PAIR(4));
            mvwprintw(wi,17,2,"FORMING WORD");
            wattroff(wi,COLOR_PAIR(4));
            pos=searchpos(c,tempword);
            forming[pos-1]=c;
            forming[l+1]='\0';
            for (j=0;j<strlen(forming);j++)
            {
                wattron(wi,COLOR_PAIR(4));
                mvwprintw(wi,18,3+j,"%c",forming[j]);
                wattroff(wi,COLOR_PAIR(4));
            }
            for(i=0;i<strlen(wrong);i++)
            {
                wattron(wi,COLOR_PAIR(2));
                mvwprintw(wi,14,2,"WRONG CHOICES");
                mvwprintw(wi,15,(2+i),"%c",wrong[i]);
                wattroff(wi,COLOR_PAIR(2));
            }
        }
        else if(check==27)
            return 27;
        refresh();
        wrefresh(wi); 
        wattron(wi,COLOR_PAIR(1));
        wattron(wi,A_REVERSE);
        box(wi,0,0);//creating the window borders
        wattroff(wi,COLOR_PAIR(1));
        wattroff(wi,A_REVERSE);

    }
    if((*chances)==6)
    {
        Display_man(wi,6);
        refresh();
        wrefresh(wi);
        delwin(wi);
        return 0;
    }
    else 
    {
        if((*chances)!=0)
            (*chances)-=1;
        refresh();
        wrefresh(wi);
        delwin(wi);
        return 1;
    }
    refresh();
    wrefresh(wi);
    delwin(wi);
}
