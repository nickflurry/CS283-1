#include "csapp.h"

void handleRequest(int connfd);

int main(int argc, char **argv){

  if(argc != 2){
    printf("Not enough arguments(needs 2)\n");
    exit(1);
  }

  int listenfd, connfd, port, clientlen;
  struct sockaddr_in clientaddr;
  struct hostent *hp;
  char *haddrp;

  port = atoi(argv[1]);

  listenfd = Open_listenfd(port);
  printf("Starting server\n");

  while(1){
    clientlen = sizeof(clientaddr);
    connfd = Accept(listenfd, (SA*)&clientaddr, &clientlen);
    hp = Gethostbyaddr((const char*)&clientaddr.sin_addr.s_addr,sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    haddrp = inet_ntoa(clientaddr.sin_addr);
    printf("server connected to %s (%s)\n", hp->h_name, haddrp);

    
    handleRequest(connfd);

    Close(connfd);
  }

  exit(0);
}

void handleRequest(int connfd)  
{
  int fd;
  size_t n;  
  char buf[MAXLINE],filePath[MAXLINE];  
  rio_t rio; 
  Rio_readinitb(&rio, connfd); 

  n = Rio_readlineb(&rio,buf,MAXLINE);
  
  //Build path
  char *ptr;
  ptr = strtok(buf," ");
  ptr = strtok(NULL," ");
  sprintf(filePath,".%s",ptr);

  fd = Open(filePath, O_RDONLY, 0);
  //send response back to client
  while(n = Rio_readn(fd, buf, sizeof(buf)) != 0){
    Rio_writen(connfd, buf, sizeof(buf));
  }

  Close(fd);
} 