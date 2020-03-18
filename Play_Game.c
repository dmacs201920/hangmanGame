#include "projectheader.h"

//function to get the player to go to the different levels
// written by Anirudh 173232 and Sushil 173247
int play_game()
{
    WINDOW *w;
    FILE *f;
    char word[20],hint[200];
    int flag=0,score=0,i=1,chances=0,c=0;
    int x;
    int it=0;
    int j,k,l;
    node *head=NULL;	
    node *t;
the:
    w=create(10,10);
    echo();
    wattron(w,COLOR_PAIR(3));
    mvwprintw(w,2+it,2,"PLEASE ENTER ONE OF THE NUMBERS GIVEN ONLY FROM THE LIST:::");
    mvwprintw(w,3+it,25,"0 or 1 or 3 or 4 or 5 or 7 or 9       ");
    wscanw(w,"%d",&c);
    wattroff(w,COLOR_PAIR(3));	
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
            for(k=0;k<40;k++)
            {
                x=Rand(0,15);
                head=linklist(head,x,f);
            }
            for (j=1;j<=7;j++)
            {
                t=search(head,j);
                strcpy(word,t->word);
                strcpy(hint,t->hint);
                word[strlen(t->word)+1]='\0';

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
            for(k=0;k<40;k++)
            {
                x=Rand(0,15);
                head=linklist(head,x,f);
            }
            for (j=1;j<=7;j++)
            {
                t=search(head,j);
                strcpy(word,t->word);
                strcpy(hint,t->hint);
                word[strlen(t->word)+1]='\0';

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
            for(k=0;k<40;k++)
            {
                x=Rand(0,15);
                head=linklist(head,x,f);
            }
            for (j=1;j<=7;j++)
            {
                t=search(head,j);
                strcpy(word,t->word);
                strcpy(hint,t->hint);
                word[strlen(t->word)+1]='\0';

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
            for(k=0;k<40;k++)
            {
                x=Rand(0,15);
                head=linklist(head,x,f);
            }
            for (j=1;j<=7;j++)
            {
                t=search(head,j);
                strcpy(word,t->word);
                strcpy(hint,t->hint);
                word[strlen(t->word)+1]='\0';

                flag=track(word,hint,&score,&chances,4);
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
                head=delete_list(head);
                return 0;
            }
            else
            {
                levelcheck(4);
                w=create(10,10);
                wattron(w,COLOR_PAIR(4));
                mvwprintw(w,5,15,"WELCOME TO THE TIME WHEN YOU HAVE A WAY TO INCREASE THE POINTS IN HUNDREDS");
                refresh();
                wrefresh(w);
                getch();
                wattroff(w,COLOR_PAIR(4));
                l=level_time();
                if(l==1)
                {
                    playerdetails(score);
                    wclear(w);
                    delwin(w);
                    goto END;
                }   
                else if(l==2)
                {
                    i=5;
                    head=delete_list(head);
                    wclear(w);
                    delwin(w);
                }
            }
            fclose(f);
            head=delete_list(head);
            goto the;
            break;
        case 5:
            head=NULL;
            f=fopen("leveltime.txt","r");
            chances=0;
            if(f==NULL)
                exit(1);
            srand(60*c);
            for(k=0;k<40;k++)
            {
                x=Rand(0,15);
                head=linklist(head,x,f);
            }
            for (j=1;j<=7;j++)
            {
                t=search(head,j);
                strcpy(word,t->word);
                strcpy(hint,t->hint);
                word[strlen(t->word)+1]='\0';

                flag=track_time(word,hint,&score,&chances);
                if(flag==0)
                {
                    fclose(f);
                    break;
                }				
                else if(flag==27)
                {
                    fclose(f);
                    head=delete_list(head);
                    return 27;
                }					
            }
            if(flag==0)
            {
                levelcheck(0);
                playerdetails(score);
                head=delete_list(head);
                return 0;
            }		
            else
                levelcheck(5);
                playerdetails(score);
                head=delete_list(head);
            ++i;
            fclose(f);
            head=delete_list(head);
            return 1;
            break;
    }
END:
    delete_list(head);
}
