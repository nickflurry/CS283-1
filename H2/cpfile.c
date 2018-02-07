#include "csapp.h"

int main(int argc, char **argv){
	int n;
	rio_t rio;
	char buf[MAXLINE];
	
	/*checks to see if it has an argument, then copies the descriptor to 0*/
	if(argc > 1){
		int fd = Open(argv[1], O_RDONLY, 0);
		dup2(fd,STDIN_FILENO);
		close(fd);
	}

	Rio_readinitb(&rio, STDIN_FILENO);
	while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
		Rio_writen(STDOUT_FILENO, buf, n);
}
