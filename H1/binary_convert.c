#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	//Checks to see if there is an argument
	if(argc > 1){
		int i;
		int array[31];
		//converts argument to an int
		int arg = atoi(argv[1]);
		
		//loops through every bit in arg to check if it is a 1 or 0
		for(i = 0; i < 31; i++){
			int j = arg >> i;
			array[i] = j & 1;
		}
		
		//prints array full of bits backwards to show binary number
		for(i = 31; i > 0; i--){
			printf("%d",array[i-1]);
		}
	}
	else{
		printf("Please include an argument");
	}	

	printf("\n");
	return 0;
}
