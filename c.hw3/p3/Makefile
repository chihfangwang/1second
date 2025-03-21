all: Main.c LocalData.o
	gcc Main.c LocalData.o

LocalData.o: LocalData.c LocalData.h
	gcc -c LocalData.c

clean:
	rm -rf *.out *.exe *.o *~ *.*~ 