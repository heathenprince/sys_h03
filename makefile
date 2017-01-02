GCC = gcc

rantest: randfile.c
	$(GCC) randfile.c -o rantest

run: rantest
	./rantest


clean:
	rm rantest
	rm foo.txt
	rm *.out
	rm *~

all:
	make rantest
	make run
	make clean
