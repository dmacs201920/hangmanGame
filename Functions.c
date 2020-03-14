#include "projectheader.h"

//declaring the various global variables in the program 
char *choices[]={"READ_DEMO","PLAY_DEMO","PLAY_GAME","DISPLAY_SCORE","EXIT"};
int n_choices=sizeof(choices)/sizeof(char*);
int row,col;

char *yes_no[]={"NO","YES"};
int yes=sizeof(yes_no)/sizeof(char*);

WINDOW *create(int a,int b)
{
	WINDOW *w;
	getmaxyx(stdscr,row,col);
	w=newwin((row*3)/4,(col*3)/4,a,b);
	start_color();

	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_YELLOW,COLOR_BLACK);
	init_pair(4,COLOR_GREEN,COLOR_BLACK);
	wattron(w,COLOR_PAIR(1));
	wattron(w,A_REVERSE);

	box(w,0,0);

	mvwprintw(w,1,36,"HANGMAN!!!");
	refresh();
	wrefresh(w);
	wattroff(w,A_REVERSE);
	wattroff(w,COLOR_PAIR(1));
	return w;
}


WINDOW *deletee(WINDOW *w)
{
delwin(w);
}

//TO display the picture of a hangman//
void game_over(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	mvwprintw(w,11,38,"\\ ");
	mvwprintw(w,12,36,"/");
	mvwprintw(w,12,38,"\\");
	wattroff(w,COLOR_PAIR(2));
} 

void game_five(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	mvwprintw(w,11,38,"\\ ");
	mvwprintw(w,12,36,"/");
	wattroff(w,COLOR_PAIR(2));
} 
void game_four(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	mvwprintw(w,11,38,"\\ ");
	wattroff(w,COLOR_PAIR(2));
} 
void game_three(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	wattroff(w,COLOR_PAIR(2));
} 
void game_two(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	wattroff(w,COLOR_PAIR(2));
} 
void game_one(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	wattroff(w,COLOR_PAIR(2));
}
void game_zero(WINDOW *w)
{
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	wattroff(w,COLOR_PAIR(2));
}

//function to display the hangman in steps
void Display_man(WINDOW *w,int level)
{
	switch(level)
	{
		case 0:game_zero(w);
		       break;
		case 1:game_one(w);
		       break;
		case 2:game_two(w);
		       break;
		case 3:game_three(w);
		       break;
		case 4:game_four(w);
		       break;
		case 5:game_five(w);
		       break;
		case 6:game_over(w);
		       break;
	}
}



//function to display the first start of tht game,the description of the game
void start_game()
{ 
	WINDOW *w;
	int i=10;
HERE:
	w=create(10,10);

	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,2,10,"___");
	mvwprintw(w,3,11,"|");
	mvwprintw(w,4,10," O");
	mvwprintw(w,5,10,"/");
	mvwprintw(w,5,11,"|");
	mvwprintw(w,5,12,"\\ ");
	mvwprintw(w,6,10,"/");
	mvwprintw(w,6,11," \\");;
	wattroff(w,COLOR_PAIR(2));
                        
	wattron(w,COLOR_PAIR(3));
	mvwprintw(w,7,2,"Hangman welcomes you to the game");
	mvwprintw(w,9,2,"The game 'HANGMAN' is a word oriented game.");
	mvwprintw(w,10,2," It consists of a set of questions in each level.");
	mvwprintw(w,12,2,"The player has to guess the answer and  enter the answer letter by letter.");
	mvwprintw(w,13,2,"Each correct  entry of a letter would add up to the score by 30");
	mvwprintw(w,14,2,"a wrong guess would decrease the score by 10.");
	mvwprintw(w,15,2,"The player is given maximum of six chances for each level.");
	mvwprintw(w,19,15,"PLEASE WAIT FOR     SECONDS");
	wattroff(w,COLOR_PAIR(3));
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,19,32,"%d",i);
	wattroff(w,COLOR_PAIR(2));
	wattron(w,COLOR_PAIR(3));
	--i;
	mvwprintw(w,20,15,"LOADING.....");
	refresh();
	wrefresh(w);
	wclear(w);
	wattroff(w,COLOR_PAIR(3));
	sleep (1);
	delwin(w);
	if(i!=-1)
		goto HERE;
	w=create(10,10);

	wattron(w,COLOR_PAIR(3));
	mvwprintw(w,10,5,"press any key on a keyboard to start the game");
	wattroff(w,COLOR_PAIR(3));
	wattron(w,COLOR_PAIR(2));
	mvwprintw(w,4,10,"O");
	mvwprintw(w,5,9,"/");
	mvwprintw(w,5,10,"|");
	mvwprintw(w,5,11,"\\");
	mvwprintw(w,6,9,"/");
	mvwprintw(w,6,10," \\");
	wattroff(w,COLOR_PAIR(2));
	refresh();
	wrefresh(w);
	getch();
	wclear(w);
	delwin(w);
}




//prints the menu for the game
void print_menu(WINDOW *w,int h)
{	
	int x,i;
	x=2;
	char *item=malloc(200);
	for(i=0;i<n_choices;i++)
	{

		sprintf(item,"%s",choices[i]);
		if(h==i+1)
		{
			wattron(w,A_STANDOUT|COLOR_PAIR(3));
			mvwprintw(w,i+1,x,"%s",choices[i]);
			wattroff(w,A_STANDOUT|COLOR_PAIR(3));
		}
		else
		{
			wattron(w,COLOR_PAIR(3));
			mvwprintw(w,i+1,x,"%s",choices[i]);
			wattroff(w,COLOR_PAIR(3));
		}
	}
	refresh();
	wrefresh(w);
}


//function to get which choice the user wants to choose
int chosen_choice()
{
	WINDOW *wi;
	wi=create(10,10);
	int highlight=1,c,y,x;
	print_menu(wi,highlight);
	while(1)
	{		
		c=getch();
		switch(c)
		{
			case KEY_UP:
				if(highlight==1)
					highlight=n_choices;
				else 
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight==n_choices)
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
			case 27:
				refresh();
				wrefresh(wi);
				delwin(wi);
				refresh();
				return 27;
				break;

		}
		print_menu(wi,highlight);
	}
	refresh();
	wrefresh(wi);
	delwin(wi);
	
}



//functions to get the level of the game and print that the level has been completed//
void levelcheck(int level)
{
	WINDOW *w;
	w=create(10,10);
    switch(level)
    {
        case 4:
        case 5:
            wattron(w,COLOR_PAIR(4));
            mvwprintw(w,10,33,"\\");
            mvwprintw(w,10,34,"O/");
            mvwprintw(w,11,34,"|");
            mvwprintw(w,12,35,"\\ ");
            mvwprintw(w,12,33,"/");
            mvwprintw(w,14,30,"Hangman is saved ");
            mvwprintw(w,16,30,"CONGRATULATIONS...");
            if(level==4)
                mvwprintw(w,18,30,"PLEASE WAIT FOR THE FINAL MISSION");
            else if(level == 5)
                mvwprintw(w,18,33,"MISSION COMPLETED!!!!!!!");
            wattroff(w,COLOR_PAIR(4));
            break;
        case 1:
        case 2:
        case 3:
            wattron(w,COLOR_PAIR(4));
            mvwprintw(w,23,15,"Conratulations... Level");
            mvwprintw(w,23,39,"%d",level);
            mvwprintw(w,23,42,"Completed");
            wattroff(w,COLOR_PAIR(4));
            break;
        case 0:
            wattron(w,COLOR_PAIR(2));
            Display_man(w,6);
            mvwprintw(w,13,20,"SORRY!!!!!!!!....... GAME OVER!!!");
            wattroff(w,COLOR_PAIR(2));
    }

	refresh();
	wrefresh(w);
	getch();
	delwin(w);
}

//SEARCHING A CERTAIN ELEMENT IN THE LIST
node *search(node* head,int x)
{
	node* t=head;
	while(t!=NULL)
	{
		if(t->num==x)
			return t;
		t=t->next;
	}
}

//function to create a linked list for the storae of the number,hint anf the word in random order 
node* linklist(node *head,int x,FILE *f)
{
	if(head==NULL)
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		temp->num=x;
		fscanf(f,"%s",temp->word);
		fgets(temp->hint,150,f);
		temp->next=NULL;
		return temp;
	}
	node *t=head;
	while(t->next!=NULL)
	{
		if(t->num==x)
			return head;
		t=t->next;
	}
	if(t->num!=x)
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		temp->num=x;
		fscanf(f,"%s",temp->word);
		fgets(temp->hint,150,f);
		temp->next=NULL;
		t->next=temp;
		return head;
	}
	return head;
}


//funcion to keep track of the entered letter and keep track of the number of mistakes made
int track(char word[],char hint[],int *score,int *chances,int level)
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
	wattron(wi,COLOR_PAIR(1));
	wattron(wi,A_REVERSE);
	mvwprintw(wi,1,36,"HANGMAN!!!");
	wattroff(wi,A_REVERSE);
	wattroff(wi,COLOR_PAIR(1));
	wattron(wi,COLOR_PAIR(3));
	mvwprintw(wi,1,70,"LEVEL::");
	mvwprintw(wi,1,79,"%d",level);
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
	mvwprintw(wi,3,79,"%d",6-(*chances));
	mvwprintw(wi,3,63,"CHANCES LEFT::");
	wattroff(wi,COLOR_PAIR(2));
	
	wattron(wi,COLOR_PAIR(4));
	for (i=0;i<l;i++)
		forming[i]='_';
	forming[i+1]='\0';
	wattroff(wi,COLOR_PAIR(4));

		
	mvwprintw(wi,6,2,"please enter letter:");
	refresh();
	wrefresh(wi);

	while((*chances)!=6 && strlen(word)!=0)
    {
        wattron(wi,COLOR_PAIR(1));
        wattron(wi,A_REVERSE);
        mvwprintw(wi,1,36,"HANGMAN!!!");
        wattroff(wi,A_REVERSE);
        wattroff(wi,COLOR_PAIR(1));
        wattron(wi,COLOR_PAIR(3));
		mvwprintw(wi,1,70,"LEVEL::");
		mvwprintw(wi,1,79,"%d",level);
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
		mvwprintw(wi,3,79,"%d",6-(*chances));
		mvwprintw(wi,3,63,"CHANCES LEFT::");
		wattroff(wi,COLOR_PAIR(2));
		wattron(wi,COLOR_PAIR(4));
		mvwprintw(wi,17,2,"FORMING WORD");
		wattroff(wi,COLOR_PAIR(4));
		wattron(wi,COLOR_PAIR(2));
		mvwprintw(wi,14,2,"WRONG CHOICES");
		wattroff(wi,COLOR_PAIR(2));
		mvwprintw(wi,6,2,"please enter letter:");
		c=getch();
		check=checkletter(c,word);
		if(check==0)
		{ 
			(*score)=(*score)-10;
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
			(*score)=(*score)+30;
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

		wclear(wi);
		wattron(wi,COLOR_PAIR(1));
		wattron(wi,A_REVERSE);
		box(wi,0,0);
		wattroff(wi,A_REVERSE);
		wattroff(wi,COLOR_PAIR(1));
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

//To check the given letter and store the scores//
int checkletter(char c,char s[])
{
    int decide;
	 
	    if(c==27)
		  decide=chosen_yes_no();
	  if(decide==2)
	  {
	      return 27;
	  }
	

	int m, k=strlen(s);
	for(int i=0;i<k;i++)
	{
		if(s[i]==c)
		{
			if(i==0)
			{
				for(m=0;m<=k;m++)
					s[m]=s[m+1];
				return i+1;
			}
			else if(i==k)
			{
				for(m=0;m<=k-1;m++)
					s[m]=s[m];
				s[m+1]='\0';
				return i+1;
			}
			else
			{
				for(m=i;m<=k;m++)
					s[m]=s[m+1];
				return i+1;
			}
		}
	}
	return 0;
}


//function to search the positon of the character in the word and return the value of the position
int searchpos(char c,char word[])
{
	for (int i=0;i<strlen(word);i++)
		if(word[i]==c)
		{
			word[i]='*';
			return i+1;
		}
	return 0;
}


//function to delete the list completely
node* delete_list(node *head)
{
	node *t1=head;
	node *t2=t1->next;
	if(t1==NULL)
		return head;
	if(t2==NULL)
	{
		free(t1);
		goto here;
	}
	while (t2!=NULL)
	{
		free (t1);
		t1=t2;
		t2=t1->next;
	}
here:	return t1;
}


int chosen_yes_no()
{
	WINDOW *wi;
	wi=create(10,10);
	int highlight=1,c,y,x;
	print_yes_no(wi,highlight);
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

		}
		print_yes_no(wi,highlight);
	}
	refresh();
	wrefresh(wi);
        delwin(wi);
	
 }

void print_yes_no(WINDOW *w,int h)
{	
	int x,i;
	x=30;
	char *item=malloc(200);
	for(i=0;i<yes;i++)
	{
                wattron(w,COLOR_PAIR(2));
		mvwprintw(w,15,20,"!!ARE YOU SURE YOU WANT TO EXIT THE GAME?\n");

		sprintf(item,"%s",yes_no[i]);
		wattroff(w,COLOR_PAIR(2));
		if(h==i+1)
		{
			wattron(w,A_STANDOUT|COLOR_PAIR(2));
			mvwprintw(w,i+18,x,"%s",yes_no[i]);
			wattroff(w,A_STANDOUT|COLOR_PAIR(2));
		}
		else
			mvwprintw(w,i+18,x,"%s",yes_no[i]);
	}
	refresh();
	wrefresh(w);
}
