.PHONY: clean

all: pwd mv rm cat 

pwd: mypwd.o
	gcc -o pwd mypwd.o

mv: mymv.o
	gcc -o mv mymv.o


rm: myrm.o
	gcc -o rm myrm.o


cat: mycat.o
	gcc -o cat mycat.o


clean:
	rm cat rm mv pwd

