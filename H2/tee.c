#include "csapp.h"

int determine_flags(int argc, char **argv);

int main(int argc, char **argv){
	int n,flags,fd;
	rio_t rio;
	char buf[MAXLINE];

	if(argc > 1){
		Rio_readinitb(&rio, STDIN_FILENO);
		
		flags = determine_flags(argc, argv);

		fd = Open(argv[argc-1], flags, 0); 

		while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
		{
			Rio_writen(STDOUT_FILENO, buf, n);
			Rio_writen(fd, buf, n);
		}
	}
	else{
		printf("Please provide a filename\n");
	}
}	

int determine_flags(int argc, char **argv){
	int opt;
	int flags = O_CREAT | O_TRUNC | O_WRONLY;
	while((opt = getopt(argc,argv,"a")) != -1){
		switch(opt){
			case 'a':
				flags = O_CREAT | O_APPEND | O_WRONLY;
				break;
			default:
				printf("Unkown Character");
		}
	}
	return flags;
}
