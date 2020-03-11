#include "projectheader.h"

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