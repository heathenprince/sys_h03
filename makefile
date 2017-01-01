default:
	make all
	make run
	make clean

all: randfile.o
	gcc randfile.o -o randfile

randfile.o: randfile.o
	gcc -c randfile.c

clean:
	rm randfile
	rm foo.txt
	rm *~
	rm *.o

run:
	./randfile
