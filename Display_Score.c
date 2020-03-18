#include "projectheader.h"
//function to display the scores of the various players in the past in the screen
// written by Anirudh 173232
void display_score() 
{
    int i,j;
    WINDOW *w;
    FILE *f;
    play D;
    char ch;
    f=fopen("playerdetails","r");
    if(f==NULL)
    {
        w=create(10,10);
        wattron(w,COLOR_PAIR(2));
        mvwprintw(w,18,19,"the file doesnt exist");
        mvwprintw(w,19,2,"please play the game before asking for the data of players played before");
        wattroff(w,COLOR_PAIR(2));
        refresh();
        wrefresh(w);
        getch();
        wclear(w);
        delwin(w);
        return ;
    }
    fread(&D,sizeof(D),1,f);
    w=create(10,10);
repeat:
    i=0;
    j=0;
    wattron(w,COLOR_PAIR(4));
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
        mvwprintw(w,14,36,"press ENTER for the next batch OR");
        mvwprintw(w,16,36,"press ESC to come to the MENU");
        refresh();
        wrefresh(w);
    }
    wattroff(w,COLOR_PAIR(4));
    ch=getch();
    if(ch==27)
    {		
        wattron(w,COLOR_PAIR(2));
        mvwprintw(w,15,36,"YOU CHOSE TO EXIT");
        wattroff(w,COLOR_PAIR(2));
        refresh();
        wrefresh(w);
        goto here;
    }
    wclear(w);
    w=create(10,10);
    if(feof(f))
    {
        wattron(w,COLOR_PAIR(2));
        mvwprintw(w,15,36,"THE END OF THE DATA PRESENT");
        wattroff(w,COLOR_PAIR(2));
        refresh();
        wrefresh(w);
        goto here;
    }
    goto repeat;
here:
    delwin(w);
    fclose(f);
    delwin(w);
}


//function to create a node for the player as a linked list
// written by Sushil 173247
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
// written by Anirudh 173232
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
// written by Anirudh 173232
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


//enters the details of the player to the linked list in decreasing order and then writes to the file
// written by Anirudh 173232
void playerdetails(int s)
{
    WINDOW *w;
    play p;
    player *head=readfile();
    player *t,*t2;
    echo();
enter:
    w=create(10,10);
    mvwprintw(w,2,2,"enter the details as asked");
    mvwprintw(w,3,2,"Name:");
    wgetstr(w,p.name);
    mvwprintw(w,4,2,"Age:");
    wscanw(w,"%d",&p.age);
    if(p.age<=0)
    {
        mvwprintw(w,5,2,"the age is invalid please enter the details again");
        refresh();
        wrefresh(w);
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
