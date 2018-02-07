#include <stdio.h> 
#include <stdlib.h> 

int main () 
 {
  char * buf;
  unsigned int num;
  num = 1 << 31;
  //since num wasn't unsigned, when it was shifted, it shifted back to 0 and buf was pointing to nothing
  buf = malloc(num) ;
  fgets (buf, 1024, stdin) ;
  printf ("%s\n", buf) ;
  return(1);
 }
