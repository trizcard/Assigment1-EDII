all: main.o ordena.o
	gcc -Wall -Wextra -o prog.exe main.o ordena.o ordena.h

run:
	./prog.exe

main.o: main.c
	gcc -Wall -Wextra -o main.o -c main.c

ordena.o: ordena.c ordena.h
	gcc -Wall -Wextra -o ordena.o -c ordena.c 

clean:
	-del -f *.exe *.o