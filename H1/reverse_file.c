#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 128

int main(int argc, char **argv)
 {	
	if(argc>1){
		char line[SIZE];
		FILE * fp = fopen(argv[1], "r");
		if (fp == NULL) return 0;

		//loop to determine # of lines in the file & size of the array
		int i = 0;
		while(fgets(line, SIZE, fp) != NULL)
		{
			i++;
		}
		fseek(fp,0,SEEK_SET);

		//create array to store strings
		char **array;
		array = malloc(i * sizeof(char*));
		char j=0;
		//store the strings into the array
		while(fgets(line, SIZE, fp) != NULL)
		{
			//allocate memory for each string
			array[j] = malloc((SIZE) * sizeof(char));
			strcpy(array[j],line);
			j++;
		}
		
		int x;
		//loop to print backwards and free memory
		for(x = i; x>0 ; x--)
		{
			printf("%s",array[x-1]);
			free(array[x-1]);
		}
		
		fclose(fp);
		
	}
	else{
		printf("Please add an argument");
	}	
	printf("\n");
	return 0;
 }
