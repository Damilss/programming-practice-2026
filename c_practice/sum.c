#include <stdio.h>

/* argv is an array of char pointers. 
 */
int main(int argc, char *argv[]){
	int num1 = argv[1][0] - '0'; 
	int num2 = argv[2][0] - '0';
	int sum = num1 + num2;

	printf("%d\n", sum); 
	return 0;
}
