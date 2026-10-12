/**
 * file: main.c 
 * Author: Emilio Ledesma
 * date: 20206-10-11
 *
 * Hold fibonnaci sequence function and entry to program
 */

#include <stdio.h>

/**
 * fib is the fucntion to print out the fibonnaci sequence term
 * by term
 * @param: int, is the number of terms in sequence
 * @return: void
 */
void fib(int n){
	
	// unable to do sequence with only 0th term or negative terms 
	if ( n < 1 ){
		printf("invalid number of terms\n");
		return; 
	}

	int previous1 = 0;
	int previous2 = 1;

	for(int i = 0; i <= n; i++){
		
		// Print current term and update previous terms
		if (i > 2) {
			int current = previous1 + previous2;
			previous2 = previous1;
			previous1 = current;
			printf("%d ", current);

		} else if (i == 1){
			printf("%d ", previous1);

		} else if (i == 2){
			printf("%d ", previous2);
		}
	}
}

// Entry point of program
int main(int argc, char *argv[]){
	int idx;

	printf("enter number for fib sequence: ");
	scanf("%d", &idx);
	printf("\nprinting sequence...\n");
	
	fib(idx);
	printf("\n");

	return 0;
}

