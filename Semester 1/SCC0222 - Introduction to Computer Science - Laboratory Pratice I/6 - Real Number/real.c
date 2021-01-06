#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    double num, float_part;
    int integer;
    scanf("%lf", &num);
    integer = (int)num / 1;
    float_part = num - integer;
    printf("%d\n", integer);
    printf("%.4lf\n", float_part);
    printf("%.0lf\n", round(num));
    return 0;
}