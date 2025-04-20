all: Main.c Contact.o Prompt.o
	gcc Main.c Contact.o Prompt.o

Contact.o: Contact.c Contact.h
	gcc -c Contact.c

Prompt.o: Prompt.c Prompt.h
	gcc -c Prompt.c

clean:
	rm -rf *.o *.out *.exe *~ .*
