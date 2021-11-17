all: main.o
	gcc -o output main.o

main.o: main.c forka.h
	gcc -c main.c

run:
	./output

clean:
	rm output
	rm *.o
