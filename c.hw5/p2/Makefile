all: Main.c SouvenirShop.o
	gcc Main.c SouvenirShop.o
SouvenirShop.o: SouvenirShop.c SouvenirShop.h Required.h
	gcc -c SouvenirShop.c
clean:
	rm -rf *.*~ *~ *.o a.*
