all: Main.c ReplaceSubstring.o
	gcc Main.c ReplaceSubstring.o

ReplaceSubstring.o: ReplaceSubstring.c ReplaceSubstring.h
	gcc -c ReplaceSubstring.c

clean:
	rm -f *.o *.out *.exe *.*~