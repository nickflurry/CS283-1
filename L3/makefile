default: clientServer

clientServer: client.c server.c
	gcc -o client client.c csapp.c -lpthread
	gcc -o server server.c csapp.c -lpthread

clean:
	-rm -f client
	-rm -f server