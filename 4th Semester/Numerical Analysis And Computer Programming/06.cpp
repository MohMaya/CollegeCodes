#include <stdio.h>
#include <math.h>

long BTD(long n) {
 int remainder;
    long decimal = 0, i=0;
    while(n != 0) {
        remainder = n%10;
        n = n/10;
        decimal = decimal + (remainder*pow(2,i));
        ++i;
    }
    return decimal;
}

int main() {
    long binary;
    printf("Enter a binary number\n");
    scanf("%ld", &binary);
    printf("Decimal number of %ld is %ld", binary, BTD(binary));
    return 0;
}


