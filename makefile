default:
	make comp
	make run
	make clean

comp: randfile.o
	gcc randfile.o -o randfile

randfile.o: 
	gcc -c randfile.c

clean:
	rm randfile
	rm foo.txt
	rm *.o
	rm *~

run:
	./randfile
