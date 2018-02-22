default: syncDir

replace.o: syncDir.c 
	gcc -c syncDir.c -o syncDir.o

replace: replace.o
	gcc syncDir.o -o syncDir

clean:
	-rm -f syncDir.o
	-rm -f syncDir