#include "projectheader.h"

//funcion to olay the demo
int play_demo()
{
	int check,d=0;
	int chances=0;
	int score=0;
	int l,i,j,pos;
	char wrong[6];
	char c;
	char tempword[20];
	char forming[20];
	char word[10]="school";
	char hint[100]="place where students go and study";
	l=strlen(word);
	strcpy(tempword,word);	

	WINDOW *wi;
	wi=create(10,10);
	mvwprintw(wi,1,36,"HANGMAN!!!");
	mvwprintw(wi,2,70,"SCORE::");
	mvwprintw(wi,2,79,"%d",score);
	mvwprintw(wi,3,2,"%s",hint);
	mvwprintw(wi,5,51,"%d",6-chances);
	mvwprintw(wi,5,36,"chance left::");
	for (i=0;i<l;i++)
		forming[i]='_';
	forming[i+1]='\0';

	mvwprintw(wi,6,2,"please enter letter:");
	refresh();
	wrefresh(wi);
	while(chances!=6 && strlen(word)!=0)
	{
		mvwprintw(wi,1,36,"HANGMAN!!!");
		mvwprintw(wi,2,70,"SCORE::");
		mvwprintw(wi,2,79,"%d",score);
		mvwprintw(wi,3,2,"%s",hint);
		mvwprintw(wi,5,51,"%d",6-chances);
		mvwprintw(wi,5,36,"chance left");
		mvwprintw(wi,6,2,"please enter letter:");
		c=getch();
		check=checkletter(c,word);
		if(check==0)
		{ 
			score=score-10;
			chances+=1;
			wrong[d]=c;
			wrong[d+1]='\0';
			++d;
			Display_man(wi,chances);
			mvwprintw(wi,5,51,"%d",6-chances);
			mvwprintw(wi,16,26,"WRONG CHOICE HAS BEEN ENTERED SO HANGMAN STARTS CREATING");
			for (j=0;j<strlen(forming);j++)
				mvwprintw(wi,19,3+j,"%c",forming[j]);

			for(i=0;i<strlen(wrong);i++)
			{
				mvwprintw(wi,14,2,"WRONG CHOICES");
				mvwprintw(wi,15,(2+i),"%c",wrong[i]);
				mvwprintw(wi,2,79,"%d",score);
			}
		}
		else if(check!=0 && check!=27)
		{
			score=score+30;
			Display_man(wi,chances);
			mvwprintw(wi,16,26,"RIGHT CHOICE HAS BEEN ENTERED SO WORD STARTS CREATING");
			mvwprintw(wi,18,2,"FORMING WORD");
			pos=searchpos(c,tempword);
			forming[pos-1]=c;
			forming[l+1]='\0';
			for (j=0;j<strlen(forming);j++)
				mvwprintw(wi,19,3+j,"%c",forming[j]);
			for(i=0;i<strlen(wrong);i++)
			{
				mvwprintw(wi,14,2,"WRONG CHOICES");
				mvwprintw(wi,15,(2+i),"%c",wrong[i]);
			}
		}
		else if(check==27)
		{
			refresh();
			wrefresh(wi);
			delwin(wi);
			return 27;
		}


		refresh();
		wrefresh(wi);

		wclear(wi);
		box(wi,0,0);
	}
	if(chances==6)		
		Display_man(wi,6);
	refresh();
	wrefresh(wi);
	delwin(wi);
	refresh();
}