all : mytop myps mylscpu
mytop: mytop.o util.o
	gcc -o mytop mytop.o util.o -lncurses -g

mytop.o: mytop.c myheader.h
	gcc -c mytop.c -lncurse -g

myps: myps.o util.o
	gcc -o myps myps.o util.o -lncurses -g

myps.o : myps.c myheader.h
	gcc -c myps.c -lncurses -g

mylscpu: mylscpu.c
	gcc -o mylscpu mylscpu.c

