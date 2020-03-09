Exe: mainprog.c functions.c
	gcc -g -o $@ mainprog.c functions.c readdemo.c play_demo.c -lncurses
