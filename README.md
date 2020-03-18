# hangmanGame.3bsc
A novice implementation of hangman Game
===========================================================================================================================
        HANGMAN GAME
============================================================================================================================
 Written by :Anirudh Narayan Pradhan(173232) and Sushil Chhetri(173247)
===========================================================================================================================
 Requirements:
            ncurses
===========================================================================================================================
features implemented:
            file handling 
            link list implementation of the list data structure
            random variable generator
            pseudo window implementation using ncurses
            usuage of keyboard keys like arrow up,down,etc.
===========================================================================================================================
 To run the program type make which will generate the executable Exe.
============================================================================================================================
 Description of the game:
        The game has built in a basic way with 5 levels.
        Using the header ncurses.h we have tred and worked in a window that has been created by us on top of the standard output window.
        The game requires a person to guess the word letter by letter by seeing the hint that has been provided by the proramer.
        The words and the hints are taken at random from the respective text files that have been fed by the programmer.
        There is a read demo and also a play demo available to help the user get a hang of the game hangman.
        At some places the user has to wait for sometime as we have used the function sleep for back counting.
============================================================================================================================
 Description of the Files:
       1:mainprog.c:
                    This file calls the different options that have been chosen by the user.
       2:Functions.c
                    This file contains some functions that are frequently called in the other files.
       3:ReadDemo.c
                    This file contains the description which the user will read if the user chooses the first option.
       4:PlayDemo.c
                    This file contains a basic game which the user can play as a trial.
       5:PlayGame.c
                    This file contains a switch case that makes the user play the different levels of the game.
                    This is the file which increases the levels and takes the different files of the different levels.
       6:FinalGame.c:
                    This is a variation of the game which emerges in the final level were the user can decide if the user wants to play this level or not.
                    Here the score increases by 100 points and for a wrong choice, decreases by 50.
       7:DisplayScore.c
                    This is the function which will display the score of the users who have played the game in the past.
       8:projectheader.h
                    This is the header file for the project.
===========================================================================================================================
