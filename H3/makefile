default: replace

replace.o: replace.c 
	gcc -c replace.c -o replace.o

replace: replace.o
	gcc replace.o -o replace

clean:
	-rm -f replace.o
	-rm -f replace