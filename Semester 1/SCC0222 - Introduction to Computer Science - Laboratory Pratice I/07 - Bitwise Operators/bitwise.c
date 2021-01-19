#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d\n", a & b);
	printf("%d\n", a | b);
	printf("%d\n", a ^ b);
	printf("%d\n", ~a);
	printf("%d\n", ~b);
	printf("%d\n", a >> 2);
	printf("%d\n", b << 2);
	return 0;
}
