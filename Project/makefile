default: tsh

tsh: myint.c myspin.c mysplit.c mystop.c tsh-skel-ck.c
	gcc -o myint myint.c
	gcc -o myspin myspin.c
	gcc -o mysplit mysplit.c 
	gcc -o mystop mystop.c
	gcc -o tsh tsh-skel-ck.c 

clean: 
	-rm -f myint
	-rm -f myspin
	-rm -f mysplit
	-rm -f mystop
	-rm -f tsh