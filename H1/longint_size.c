#define BITS_IN_BYTE 8

int main(){
	//instantiates a long int into memory
	long int num;

	//creates a pointer to the address of num, & another pointer for the next position
	long int *ptr= &num;
	long int *next = ptr++;
	
	//subtracts the value of the two pointers to determine size of long int
	int size = ((char *)ptr-(char *)next) * BITS_IN_BYTE;

	printf("%d\n", size);
	return 0;
}
