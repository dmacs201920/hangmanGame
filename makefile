cc= gcc
c=-g -c
o=-g -o
l=-lncurses

Exe: mainprog.o Functions.o Read_Demo.o Play_Demo.o Play_Game.o Display_Score.o Final_Game.o
	$(cc) $(o) $@ mainprog.o Functions.o Read_Demo.o Play_Demo.o Play_Game.o Display_Score.o  Final_Game.o $(l)

mainprog.o: mainprog.c projectheader.h
	$(cc) $(c) mainprog.c $(l)
Functions.o: Functions.c projectheader.h
	$(cc) $(c) Functions.c $(l)
Read_Demo.o: Read_Demo.c projectheader.h
	$(cc) $(c) Read_Demo.c $(l)
Play_Demo.o: Play_Demo.c projectheader.h
	$(cc) $(c) Play_Demo.c $(l)
Play_Game.o: Play_Game.c projectheader.h
	$(cc) $(c) Play_Game.c $(l)
Display_Score.o: Display_Score.c projectheader.h
	$(cc) $(c) Display_Score.c $(l)
Final_Game.o:Final_Game.c projectheader.h
	$(cc) $(c) Final_Game.c $(l)

clean:
	rm  mainprog.o Functions.o Read_Demo.o Play_Demo.o Play_Game.o Display_Score.o Final_Game.o
