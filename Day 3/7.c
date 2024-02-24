// Write a program for the given pattern using recursion
// If n=4                    1
//                           1   2
//                           1   2    3
//                           1   2    3    4

#include <stdio.h>
void printRow(int n) {
    if (n == 0)
        return;
    printRow(n - 1);
    printf("%d ", n);
}

void printPattern(int n) {
    if (n == 0)
        return;
    printPattern(n - 1);
    printRow(n);
    printf("\n");
}

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printPattern(rows);

    return 0;
}


