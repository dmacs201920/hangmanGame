#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include "projectheader.h"

//declaring the various global variables in the program Hangman 
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

	init_pair(0,COLOR_BLUE,COLOR_BLACK);
	wattron(w,COLOR_PAIR(0));

	wborder(w,'|','|','-','-','+','+','+','+');
//	box(w,0,0);

	mvwprintw(w,1,36,"HANGMAN!!!");
	refresh();
	wrefresh(w);
	wattroff(w,COLOR_PAIR(0));
	return w;
}


WINDOW *deletee(WINDOW *w)
{
delwin(w);
}

//TO display the picture of a hangman//
void game_over(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	mvwprintw(w,11,38,"\\ ");
	mvwprintw(w,12,36,"/");
	mvwprintw(w,12,38,"\\");
	getch();
} 

void game_five(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	mvwprintw(w,11,38,"\\ ");
	mvwprintw(w,12,36,"/");
} 
void game_four(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
	mvwprintw(w,11,38,"\\ ");
} 
void game_three(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
	mvwprintw(w,11,37,"|");
} 
void game_two(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
	mvwprintw(w,11,36,"/");
} 
void game_one(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
	mvwprintw(w,10,37,"O");
}
void game_zero(WINDOW *w)
{
	mvwprintw(w,8,36,"___");
	mvwprintw(w,9,37,"|");
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

//TO show the demo of the game//
void Demo_game()
{
	WINDOW *w;
	w=create(10,10);
	char c;

	mvwprintw(w,1,1,"start");
	mvwprintw(w,14,8,"press ESC to go back to the menu");
	mvwprintw(w,2,1,"Hint:Name  a fruit that becomes yellow when it is ripen and is sour when it is raw");
	mvwprintw(w,3,1,"*****");
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


//function to display the first start of tht game,the description of the game
void start_game()
{ 
	WINDOW *w;
	int i=9;
HERE:
	w=create(10,10);
//start_color();
	//init_pair(0,COLOR_RED,COLOR_BLACK);
//	init_pair(0,COLOR_BLUE,COLOR_BLACK);
	
//	wattron(w,COLOR_PAIR(0));
	mvwprintw(w,2,10,"___");
	mvwprintw(w,3,11,"|");
	mvwprintw(w,4,10," O");
	mvwprintw(w,5,10,"/");
	mvwprintw(w,5,11,"|");
	mvwprintw(w,5,12,"\\ ");
	mvwprintw(w,6,10,"/");
	mvwprintw(w,6,11," \\");
                        
	mvwprintw(w,7,2,"Hangman welcomes you to the game");
	mvwprintw(w,9,2,"The game 'HANGMAN' is a word oriented game.");
	mvwprintw(w,10,2," It consists of a set of questions in each level.");
	mvwprintw(w,12,2,"The player has to guess the answer and  enter the answer letter by letter.");
	mvwprintw(w,13,2,"Each correct  entry of a letter would add up to the score by 30");
	mvwprintw(w,13,2,"a wrong guess would decrease the score by 10.");
	mvwprintw(w,14,2,"The player is given maximum of six chances for each level.");
	mvwprintw(w,19,15,"PLEASE WAIT FOR     SECONDS");
	mvwprintw(w,19,32,"%d",i);
	--i;
	mvwprintw(w,20,15,"LOADING.....");
	refresh();
	wrefresh(w);
	wclear(w);
//	wattroff(w,COLOR_PAIR(0));
	sleep (1);
	delwin(w);
	if(i!=0)
		goto HERE;
	w=create(10,10);

//	wattron(w,COLOR_PAIR(0));
	mvwprintw(w,10,5,"press any key on a keyboard to start the game");
	mvwprintw(w,4,10,"O");
	mvwprintw(w,5,9,"/");
	mvwprintw(w,5,10,"|");
	mvwprintw(w,5,11,"\\");
	mvwprintw(w,6,9,"/");
	mvwprintw(w,6,10," \\");
	refresh();
	wrefresh(w);
	getch();
	wclear(w);
	delwin(w);
//	wattroff(w,COLOR_PAIR(0));
}

//function to display the scores of the various players in the past in the screen
void display_score() 
{
	int i,j;
	WINDOW *w;
	FILE *f;
	play D;
	f=fopen("playerdetails","r");
	if(f==NULL)
	{
		w=create(10,10);
		mvwprintw(w,18,19,"the file doesnt exist");
		mvwprintw(w,19,2,"please play the game before asking for the data of players played before");
		refresh();
		wrefresh(w);
		getch();
		wclear(w);
		delwin(w);
		return ;
	}
	fread(&D,sizeof(D),1,f);
	w=create(10,10);
repeat:i=0;
       j=0;
       while(!feof(f)&&j<7)
       {
	       mvwprintw(w,(1+i),2,"name:");
	       mvwprintw(w,(1+i),10,"%s",D.name);
	       mvwprintw(w,(2+i),2,"age:");
	       mvwprintw(w,(2+i),10,"%d",D.age);
	       mvwprintw(w,(3+i),2,"Score:");
	       mvwprintw(w,(3+i),10,"%d",D.score);
	       i+=4;
	       ++j;
	       fread(&D,sizeof(D),1,f);
	       mvwprintw(w,14,36,"press ENTER for the next batch");
	       refresh();
	       wrefresh(w);
       }
       getch();
	wclear(w);
	w=create(10,10);
       if(feof(f))
       {
	       mvwprintw(w,15,36,"THE END OF THE DATA PRESENT");
	       refresh();
	       wrefresh(w);
	       goto here;
       }
//	getch();
	goto repeat;
here:
	delwin(w);
	fclose(f);
	delwin(w);
}

//function to create a node for the player as a linked list
player* createnode(play p)
{
	player* temp;
	temp=(player*)malloc(sizeof(player));
	if(temp==NULL)
		exit(1);
	else
	{
		strcpy(temp->name,p.name);
		temp->age=p.age;
		temp->score=p.score;
		temp->next=NULL;
	}
	return temp;
}
//function reades the file and creates the linked list of the player details stored in the file
player *readfile()
{
	FILE *f;
	f=fopen("playerdetails","r+");
	if(f==NULL)
		f=fopen("playerdetails","a+");
	play p;
	strcpy(p.name," ");
	p.age=0;
	p.score=0;
	player *head=createnode(p);
	player *temp=head;
	while (!feof(f))
	{
		fread(&p,sizeof(play),1,f);
		if(strcmp(temp->name,p.name)!=0)
		{
			temp->next =createnode(p);
			temp=temp->next;
		}
	}
	fclose(f);
	return head->next;
}


//INSERTING THE ELEMENTS AT DESENDING ORDER
player* InsertDescendInList(player* head,play x)
{
	player *t=head;
	player *temp=createnode(x);
	if(t==NULL)
		return temp;
	if(t->score <= temp->score)
	{
		temp->next=t;
		head=temp;
		return head;
	}
	while(t!=NULL)
	{
		if(t->score > x.score && (t->next==NULL || t->next->score <=x.score) )
		{
			temp->next=t->next;
			t->next=temp;
			return head;
		}	
		t=t->next;
	}
	return head;
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
			wattron(w,A_STANDOUT);
			mvwprintw(w,i+1,x,"%s",choices[i]);
			wattroff(w,A_STANDOUT);
		}
		else
			mvwprintw(w,i+1,x,"%s",choices[i]);
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

//enters the details of the player to the linked list in decreasing order and then writes to the file
void playerdetails(int s)
{
	WINDOW *w;
	play p;
	player *head=readfile();
	player *t,*t2;
	echo();
enter:
	w=create(10,10);
	game_over(w);	
	mvwprintw(w,2,2,"enter the details as asked");
	mvwprintw(w,3,2,"Name:");
	wgetstr(w,p.name);
	mvwprintw(w,4,2,"Age:");
	wscanw(w,"%d",&p.age);
	if(p.age<=0)
	{
		mvwprintw(w,5,2,"the age is invalid please enter the details again");
		goto enter;
	}
	p.score=s;
	head=InsertDescendInList(head,p);
	t2=head;
	FILE *f;
	f=fopen("playerdetails","w");

	while(t2!=NULL)
	{
		t=t2;
		strcpy(p.name,t->name);
		p.age=t->age;
		p.score=t->score;
		if(strcmp(p.name," ")!=0)
		    fwrite(&p,sizeof(play),1,f);
		t2=t->next;
		free(t);
	}
	fclose(f);
	refresh();
	wrefresh(w);
	delwin(w);
	noecho();
}


//function to get the player to go to the different levels
int play_game()
{
	WINDOW *w;
	FILE *f;
	char word[20],hint[200];
	int flag=0,score=0,i=1,chances=0,c=0;
	int x;
	int it=0;
	node *head=NULL;
	
	node *t;
the:
	w=create(10,10);
	echo();
	mvwprintw(w,2+it,2,"PLEASE ENTER ONE OF THE NUMBERS GIVEN ONLY FROM THE LIST:::");
	mvwprintw(w,3+it,25,"0 or 1 or 3 or 4 or 5 or 7 or 9       ");
	wscanw(w,"%d",&c);
	if(c==0 || c==1 || c==3 || c==4 || c==5 ||c==7 ||c==9 )
		goto next;
	else
	{
		it+=2;
		if(it==26)
			it=0;
		goto the;
	}
next:
	refresh();
	wrefresh(w);
	wclear(w);
	delwin(w);
	noecho();
	switch(i)
	{
		case 1:
			f=fopen("level1.txt","r");
			if(f==NULL)
				exit(1);
			srand(60*c);
			for(int k=0;k<40;k++)
			{
				x=Rand(0,15);
				head=linklist(head,x,f);
			}
			for (int j=1;j<=7;j++)
			{
				t=search(head,j);
				strcpy(word,t->word);
				strcpy(hint,t->hint);

				flag=track(word,hint,&score,&chances,1);
				if(flag==0)
				{
					fclose(f);
					break;
				}
				else if(flag==27)
				{
					fclose(f);
					return 27;
				}
			}
			if(flag==0)
			{
				levelcheck(0);
				playerdetails(score);
				return 0;
			}
			else
				levelcheck(1);
			++i;
			fclose(f);
			head=delete_list(head);

			goto the;
			break;
		case 2:
			head=NULL;
			f=fopen("level2.txt","r");
			if(f==NULL)
				exit(1);
			srand(60*c);
			for(int k=0;k<40;k++)
			{
				x=Rand(0,15);
				head=linklist(head,x,f);
			}
			for (int j=1;j<=7;j++)
			{
				t=search(head,j);
				strcpy(word,t->word);
				strcpy(hint,t->hint);

				flag=track(word,hint,&score,&chances,2);
				if(flag==0)
				{
					fclose(f);
					break;
				}				
				else if(flag==27)
				{
					fclose(f);
					return 27;
				}					
			}
			if(flag==0)
			{
				levelcheck(0);
				playerdetails(score);
				return 0;
			}		
			else
				levelcheck(2);
			++i;
			fclose(f);
			head=delete_list(head);
			goto the;
			break;
		case 3:
			head=NULL;
			f=fopen("level3.txt","r");
			if(f==NULL)
				exit(1);
			srand(60*c);
			for(int k=0;k<40;k++)
			{
				x=Rand(0,15);
				head=linklist(head,x,f);
			}
			for (int j=1;j<=7;j++)
			{
				t=search(head,j);
				strcpy(word,t->word);
				strcpy(hint,t->hint);

				flag=track(word,hint,&score,&chances,2);
				if(flag==0)
				{
					fclose(f);
					break;
				}				
				else if(flag==27)
				{
					fclose(f);
					return 27;
				}					
			}
			if(flag==0)
			{
				levelcheck(0);
				playerdetails(score);
				return 0;
			}		
			else
				levelcheck(3);
			++i;
			fclose(f);
			head=delete_list(head);
			goto the;
			break;
		case 4:
			head=NULL;
			f=fopen("levelhard.txt","r");
			if(f==NULL)
				exit(1);
			srand(60*c);
			for(int k=0;k<40;k++)
			{
				x=Rand(0,15);
				head=linklist(head,x,f);
			}
			for (int j=1;j<=7;j++)
			{
				t=search(head,j);
				strcpy(word,t->word);
				strcpy(hint,t->hint);

				flag=track(word,hint,&score,&chances,3);
				if(flag==0)
				{
					fclose(f);
					break;
				}			
				else if(flag==27)
				{
					fclose(f);
					return 27;
				}
			}
			playerdetails(score);
			if(flag==0)
			{
				levelcheck(0);
				return 0;
			}
			else
				levelcheck(4);
			fclose(f);
			head=delete_list(head);
			return 1;
			break;
	}
	delete_list(head);
}

//functions to get the level of the game and print that the level has been completed//
void levelcheck(int level)
{
	WINDOW *w;
	w=create(10,10);
	if(level==4)
	{  mvwprintw(w,10,33,"\\");
		mvwprintw(w,10,34,"O/");
		mvwprintw(w,11,34,"|");
		mvwprintw(w,12,35,"\\ ");
		mvwprintw(w,12,33,"/");
		mvwprintw(w,14,30,"Hangman is saved ");
		mvwprintw(w,15,30,"MISSION COMPLETED");
		mvwprintw(w,16,30,"CONGRATULATIONS...");
	}
	else if(level==1 || level==2 || level==3)
	{mvwprintw(w,23,15,"Conratulations... Level");
		mvwprintw(w,23,39,"%d",level);
		mvwprintw(w,23,42,"Completed");
	} 
	else if(level==0)
	{
		Display_man(w,6);
		mvwprintw(w,13,20,"SORRY!!!!!!!!....... GAME OVER!!!");
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
	mvwprintw(wi,1,36,"HANGMAN!!!");
	mvwprintw(wi,1,70,"LEVEL::");
	mvwprintw(wi,1,79,"%d",level);
	mvwprintw(wi,2,70,"SCORE::");
	mvwprintw(wi,2,79,"%d",(*score));
	mvwprintw(wi,4,2,"HINT::");
	mvwprintw(wi,4,8,"%s",hint);
	mvwprintw(wi,3,79,"%d",6-(*chances));
	mvwprintw(wi,3,63,"CHANCES LEFT::");
	for (i=0;i<l;i++)
		forming[i]='_';
	forming[i+1]='\0';

		
	mvwprintw(wi,6,2,"please enter letter:");
	refresh();
	wrefresh(wi);

	while((*chances)!=6 && strlen(word)!=0)
	{
		mvwprintw(wi,1,36,"HANGMAN!!!");
		mvwprintw(wi,1,70,"LEVEL::");
		mvwprintw(wi,1,79,"%d",level);
		mvwprintw(wi,2,70,"SCORE::");
		mvwprintw(wi,2,79,"%d",(*score));
		mvwprintw(wi,4,2,"HINT::");
		mvwprintw(wi,4,8,"%s",hint);
		mvwprintw(wi,3,79,"%d",6-(*chances));
		mvwprintw(wi,3,63,"CHANCES LEFT::");
		mvwprintw(wi,17,2,"FORMING WORD");
		mvwprintw(wi,14,2,"WRONG CHOICES");
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
			mvwprintw(wi,3,79,"%d",6-(*chances));
			for (j=0;j<strlen(forming);j++)
				mvwprintw(wi,18,3+j,"%c",forming[j]);
			for(i=0;i<strlen(wrong);i++)
			{
				mvwprintw(wi,14,2,"WRONG CHOICES");
				mvwprintw(wi,15,(2+i),"%c",wrong[i]);
				mvwprintw(wi,2,79,"%d",(*score));
			}
		}
		else if(check!=0 && check!=27)
		{
			(*score)=(*score)+30;
			Display_man(wi,(*chances));
			mvwprintw(wi,17,2,"FORMING WORD");
			pos=searchpos(c,tempword);
			forming[pos-1]=c;
			forming[l+1]='\0';
			for (j=0;j<strlen(forming);j++)
				mvwprintw(wi,18,3+j,"%c",forming[j]);
			for(i=0;i<strlen(wrong);i++)
			{
				mvwprintw(wi,14,2,"WRONG CHOICES");
				mvwprintw(wi,15,(2+i),"%c",wrong[i]);
			}
		}
		else if(check==27)
			return 27;
		refresh();
		wrefresh(wi);

		wclear(wi);
		box(wi,0,0);
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
                
		mvwprintw(w,15,20,"!!ARE YOU SURE YOU WANT TO EXIT THE GAME?\n");

		sprintf(item,"%s",yes_no[i]);
		if(h==i+1)
		{
			wattron(w,A_STANDOUT);
			mvwprintw(w,i+18,x,"%s",yes_no[i]);
			wattroff(w,A_STANDOUT);
		}
		else
			mvwprintw(w,i+18,x,"%s",yes_no[i]);
	}
	refresh();
	wrefresh(w);
}


