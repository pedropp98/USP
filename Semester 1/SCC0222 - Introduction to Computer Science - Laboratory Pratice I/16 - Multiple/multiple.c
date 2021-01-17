#include<stdio.h>
#include<stdlib.h>

#define or ||

int main(void){
    int n_prints, num1, num2;
    scanf("%d %d %d", &n_prints, &num1, &num2);
    for(int i = 0, check_multiple = 0; i < n_prints; check_multiple++){
        if(check_multiple % num1 == 0 or check_multiple % num2 == 0){
            printf("%d\n", check_multiple);
            i++;
        }
    }
    return 0;
}