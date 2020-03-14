
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
//HANGMAN PROJECT/////
 struct player
{char name[20];
	int age;
	int score;
	struct player *next;
};
typedef struct player player;


typedef struct play
{char name[20];
 int age;
 int score;
} play;


typedef struct node
{  
	char hint[150],word[20];
	int num;
	struct node *next;
}node;

//function to create/delele  a window and display the box
WINDOW *create(int a,int b);
WINDOW *deletee(WINDOW *w);

//functions to display the hangman
void game_over(WINDOW *w);
void game_zero(WINDOW *w);
void game_one(WINDOW *w);
void game_two(WINDOW *w);
void game_three(WINDOW *w);
void game_four(WINDOW *w);
void game_five(WINDOW *w);
void Demo_game();

//checks each letter of the word
int checkletter(char c,char s[]);

void display_score();//displays the score

void Display_man(WINDOW *w,int level);//calls the various levels of the hangman


//functions that will read the file,create the linked list of the details stored in the file,insert the current players details in the list and then to the file
player* createnode(play p);
player *readfile();
void playerdetails(int s);
player* InsertDescendInList(player* head,play x);


void  start_game();//the start of the game

//prints the menu for the game
void print_menu(WINDOW *w,int h);

//function to get which choice has been chosen
int chosen_choice();

//funcion to keep track of the entered letter and keep track of the number of mistakes made
int track(char s[],char hint[],int *score,int *chances,int level);

	
//function to get the player to go to the different levels
int play_game();

//functions to check the level of the game//
void levelcheck(int level);

//defining random to generate ramdom integers
#define Rand(a,b) (a+(rand()%(b-a)))

//function to create the linked list of the distinct integers with the words
node* linklist(node *head,int x,FILE *f);


//SEARCHING A CERTAIN ELEMENT IN THE LIST
node *search(node* head,int x);

//function to delete the list completely
node* delete_list(node *head);

//funcion to olay the demo
int play_demo();

//function to search the positon of the character in the word and return the value of the position
int searchpos(char c,char word[]);

int chosen_yes_no();
void print_yes_no(WINDOW *w,int h);

int chosen_time();
void print_time(WINDOW *w,int h);


 int level_time();
int track_time(char word[],char hint[],int *score,int *chances);
