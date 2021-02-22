#include<stdio.h>
#include<stdlib.h>

// Function definition
long an_term(long, long, long);
double sn_sum(long, long, long);

// Main function
int main(void){
    long a1, common_difference, n, a_n;
    scanf("%ld %ld %ld", &a1, &common_difference, &n); // Reads 3 numbers from stdin
    a_n = an_term(a1, common_difference, n); // Gets the result from an_term function
    // Prints the result
    printf("%ld\n", a_n);
    printf("%.0lf\n", sn_sum(a1, a_n, n)); // Gets the result from sn_sum function and prints it
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