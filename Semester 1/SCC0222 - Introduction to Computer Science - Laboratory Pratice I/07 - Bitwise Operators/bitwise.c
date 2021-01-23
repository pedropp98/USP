#include <stdio.h>
#include <stdlib.h>

// Main function
int main(void){
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	// Prints the results from bitwise operators
	printf("%d\n", a & b);
	printf("%d\n", a | b);
	printf("%d\n", a ^ b);
	printf("%d\n", ~a);
	printf("%d\n", ~b);
	printf("%d\n", a >> 2);
	printf("%d\n", b << 2);
	return 0;
}
