===========================================================================================================================
        ||   $$    $$        $$$$  $$      $$  $$$$$$$$$$$  $$$     $$$        $$$$  $$      $$          ||
        ||    $$    $$       $   $  $$$     $$  $$       $$  $$ $   $ $$       $   $  $$$     $$         ||
        ||     $$    $$      $$  $$  $$ $    $$  $$           $$  $ $  $$      $$  $$  $$ $    $$        ||
        ||      $$$$$$$$     $$$$$$$  $$  $   $$  $$           $$   $   $$     $$$$$$$  $$  $   $$       ||
        ||       $$$$$$$$    $$$$$$$$  $$   $  $$  $$           $$       $$    $$$$$$$$  $$   $  $$      ||
        ||        $$    $$   $$     $$  $$    $ $$  $$   $$$$$$  $$       $$   $$     $$  $$    $ $$     ||
        ||         $$    $$  $$      $$  $$     $$$  $$$$$$$$ $$  $$       $$  $$      $$  $$     $$$    ||
        ||          $$    $$ $$       $$  $$      $$  $$$$$$$$ $$  $$       $$ $$       $$  $$      $$   ||
        ||                                                      $$                                       ||
        ||                                                       $$                                      ||
============================================================================================================================
 Written by :Anirudh Narayan Pradhan(173232) and Sushil Chhetri(173247)

 Requirements:
        ncurses
========================================================================================================================
 To run the program the user needs to use the makefile that has been created.
 the name of the executable is Exe
=========================================================================================================================
 Description of the game:
        The game has built in a basic way with 5 levels.
        Using the header ncurses.h we have tred and worked in a window that has been created by us on top of the standard output window.
        The game requires a person to guess the word letter by letter by seeing the hint that has been provided by the proramer.
        The words and the hints are taken at random from the respective text files that have been fed by the programmer.
        There is a read demo and also a play demo available to help the user get a hang of the game hangman.
        At some places the user has to wait for sometime as we have used the function sleep for back counting.
==========================================================================================================================
 Description of the Files that are there:
        mainprog.c:
                    This file calls the different options that have been chosen by the user.   
        Functions.c
                    This file contains some functions that are frequently called in the other files.
        ReadDemo.c
                    This file contains the description which the user will read if the user chooses the option READ_DEMO.
        PlayDemo.c
                    This file contains a basic game which the user can play as a trial.
        PlayGame.c
                    This file contains a switch case that makes the user play the different levels of the game.
                    This is the file which increases the levels and takes the different files of the different levels.
        FinalGame.c:
                    This is a variation of the game which emerges in the final level were the user can decide if the user wants to play this level or not.
                    Here the score increases by 100 points and for a wrong choice, decreases by 50.
        DisplayScore.c
                    This is the function which will display the score of the users who have played the game in the past.
===========================================================================================================================
