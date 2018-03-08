#include "csapp.h" 
/* usage: ./echoclient host port file*/
int main(int argc, char **argv){

  if(argc != 4){
    printf("Wrong number of arguments(must be 3)");
    exit(1);
  }

  int clientfd, port;
  char *host, buf[MAXLINE], *file;
  rio_t rio;
  host = argv[1];
  port = atoi(argv[2]);
  file = argv[3];
  
  clientfd = Open_clientfd(host,port);
  printf("Connected to client\n");

  //create string to send to server
  sprintf(buf,"GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n",file,host);

  Rio_readinitb(&rio,clientfd);

  //send request to server
  Rio_writen(clientfd, buf, strlen(buf));
  
  //receive responses back
  ssize_t read;
  while((read = Rio_readnb(&rio,buf,MAXLINE)) != 0){
    printf("%s",buf);
  }
  
  Close(clientfd);
  exit(0);
}
