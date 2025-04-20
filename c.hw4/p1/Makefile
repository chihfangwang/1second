all: Main.c ReverseString.o
	gcc Main.c ReverseString.o

ReverseString.o: ReverseString.c ReverseString.h
	gcc -c ReverseString.c

clean:
	rm -rf *.o *.out *.exe *~