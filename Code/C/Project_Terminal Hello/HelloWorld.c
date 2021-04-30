#include <stdio.h>
//
int main(int argc, char *argv[]){

	if (argc == 2){
		printf("Hello: %s\n", argv[1]);
	}
	else {
		fprintf(stderr, "Error: 0x01. No user name : (\n");
		return 1;
	}
	return 0;
}
