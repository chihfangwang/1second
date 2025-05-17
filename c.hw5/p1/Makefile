all: Main.c StringBox.o
	gcc Main.c StringBox.o
StringBox.o: StringBox.c StringBox.h
	gcc -c StringBox.c
clean:
	rm -f *.o *.out *~
run:
	make clean && make && clear && ./a.out