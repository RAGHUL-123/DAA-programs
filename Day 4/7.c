// Write a program to compute container loader Problem.
#include <stdio.h>

void containerLoading(int items[], int n, int capacity) {
    int containers = 1;  
    int currentCapacity = capacity; 

    for (int i = 0; i < n; i++) {
        if (items[i] <= currentCapacity) {
            printf("Item %d fits in Container %d\n", i + 1, containers);
            currentCapacity -= items[i]; 
        } else {
            containers++;
            printf("Item %d goes into Container %d\n", i + 1, containers);
            currentCapacity = capacity - items[i];  
        }
    }

    printf("\nTotal number of containers used: %d\n", containers);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int items[n];
    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    int capacity;
    printf("Enter the capacity of each container: ");
    scanf("%d", &capacity);

    printf("\nContainer Loading:\n");
    containerLoading(items, n, capacity);

    return 0;
}