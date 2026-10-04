#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SIZE 10 

/*
 * Author: Emilio Scott
 * calloc_check is for experimentation with the callc() memory allocation
 */

// our array
int *arr;

/*
 * main.c entry point
 * @param: int arc, argument counter
 * @param: char *argv[], argument variables
 * @return: int, status code, 0 if success, non-zero if something went wrong
 */ 
int main(int argc, char *argv[]) {

	int *arr = calloc(SIZE, sizeof(int));

	for (int i = 0; i < SIZE; i++){
	
	/*	
		if (arr[i] == 0){
			printf("idx number %d passed!\n", i);
		} else {
			printf("idx number %d FAILED\n", i);
		
		}
	*/
	
		assert(arr[i] == 0);

	}
	
	free(arr);	

	return 0; 
}
