#include<stdio.h>
#include<stdlib.h>

// Function definition
long an_term(long, long, long);
double sn_sum(long, long, long);

// Main function
int main(void){
    long a1, common_difference, n, an;
    double Sn;
    scanf("%ld %ld %ld", &a1, &common_difference, &n); // Reads 3 numbers from stdin
    an = an_term(a1, common_difference, n); // Gets the result from an_term function
    Sn = sn_sum(a1, an, n); // Gets the result from sn-sum function
    // Prints the result
    printf("%ld\n", an);
    printf("%.0lf\n", Sn);
    return 0;
}

// Function declaration
// Finds the a_n term from a arithmetic progression
long an_term(long a1, long common_diff, long n){
    return a1 + common_diff * (n - 1);
}

// Calculates the sum of a_n terms in a arithmetic progression
double sn_sum(long a1, long an, long n){
    return ((a1 + an) * n) / 2;
}