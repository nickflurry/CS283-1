#include "csapp.h"

#define MAXTHREADS 32754 /*Maximum number of threads */

void *thread(void *vargp);

int main(int argc, char **argv)
{
  if(argc != 2){
    printf("Wrong number of arguments (Only one)\n");
    exit(-1);
  }

  //creates array of threads
  pthread_t tid[MAXTHREADS];
  int num = atoi(argv[1]);
  int i;

  //creates thread num times
  for(i = 0; i < num; i++){
    Pthread_create(&tid[i],NULL,thread,NULL);
  }
  
  //joins all threads
  for(i = 0; i < num; i++){
    Pthread_join(tid[i],NULL);
  }
  exit(0);
}

void *thread(void *vargp)
{
  printf("Hello,World!\n");
  return NULL;
}