all: Main.c Score.o
	gcc Main.c Score.o
Score.o: Score.c Score.h
	gcc -c Score.c
clean:
	rm -f *.o* a.out *.c~