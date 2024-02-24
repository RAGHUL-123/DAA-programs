// Write a program to find the reverse of a given number using recursive.

#include <stdio.h>
#include <math.h>

// Recursive function to find the reverse of a number
int reverse(int num) {
    if (num == 0)
        return 0;
    else
        return (num % 10) * pow(10, (int)log10(num)) + reverse(num / 10);
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    int reversedNum = reverse(num);
    printf("Reverse of %d is %d\n", num, reversedNum);

    return 0;
}