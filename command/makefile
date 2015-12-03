.PHONY: clean

all: pwd mv rm cat ln tail cp rmdir tee cd ls clear

pwd: mypwd.o
	gcc -o pwd mypwd.o

mv: mymv.o
	gcc -o mv mymv.o

rm: myrm.o
	gcc -o rm myrm.o

cat: mycat.o
	gcc -o cat mycat.o

ln: myln.o
	gcc -o ln myln.o

tail: mytail.o
	gcc -o tail mytail.o

cp: mycp.o
	gcc -o cp mycp.o

rmdir: myrmdir.o
	gcc -o rmdir myrmdir.o

tee: mytee.o
	gcc -o tee mytee.o

cd: mycd.o
	gcc -o cd mycd.o
ls: myls.o
	gcc -o ls myls.o
clear:
	rm mycat.o myrm.o mymv.o mypwd.o myln.o mytail.o mycp.o myrmdir.o mytee.o mycd.o myls.o

clean:
	rm cat rm mv pwd ln tail cp rmdir tee cd ls


