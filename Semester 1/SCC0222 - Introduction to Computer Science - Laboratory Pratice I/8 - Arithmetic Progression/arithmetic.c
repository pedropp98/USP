#include<stdio.h>
#include<stdlib.h>

long an_term(long, long, long);
double sn_sum(long, long, long);

int main(void){
    long a1, common_difference, n, an;
    double Sn;
    scanf("%ld %ld %ld", &a1, &common_difference, &n);
    an = an_term(a1, common_difference, n);
    Sn = sn_sum(a1, an, n);
    printf("%ld\n", an);
    printf("%.0lf\n", Sn);
    return 0;
}

long an_term(long a1, long common_diff, long n){
    return a1 + common_diff * (n - 1);
}

double sn_sum(long a1, long an, long n){
    return ((a1 + an) * n) / 2;
}