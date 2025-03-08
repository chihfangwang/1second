all: Main.c checkID.o
	gcc Main.c checkID.o
checkID.o: checkID.c checkID.h
	gcc -c checkID.c
clean:
	rm -f *.o *~ *.*~ a.out