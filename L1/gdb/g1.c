#include <ctype.h> 
#include <stdio.h> 

int main () 
 {
  char c;
  c = fgetc (stdin) ;
    while (c != EOF){ 
        if (isalnum (c) ) 
            printf ("%c\n", c) ;
        c = fgetc (stdin) ;
    }
//while loop needed to have brackets to in case the fgetc
  return(1);
 }
