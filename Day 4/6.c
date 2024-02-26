// Write a program to perform graph coloring problem using backtrackin

#include <stdio.h>
#include <stdbool.h>

#define V 4

int graph[V][V] = {
    {0, 1, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 0, 1},
    {1, 1, 1, 0}
};

int colors[V];

bool isSafe(int vertex, int color, int m) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool colorGraphUtil(int vertex, int m) {
    if (vertex == V) {
        return true; // All vertices are colored
    }

    for (int c = 0; c < m; c++) {
        if (isSafe(vertex, c, m)) {
            colors[vertex] = c;

            if (colorGraphUtil(vertex + 1, m)) {
                return true;
            }

            colors[vertex] = -1; // Backtrack
        }
    }

    return false;
}

void colorGraph(int m) {
    if (colorGraphUtil(0, m)) {
        printf("Graph can be colored using %d colors.\n", m);
        printf("Coloring: ");
        for (int i = 0; i < V; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }
}

int main() {
    int m; // Number of colors
    printf("Enter the number of colors: ");
    fflush(stdout); // Ensure the prompt is displayed in the output panel
    scanf("%d", &m);

    for (int i = 0; i < V; i++) {
        colors[i] = -1; // Initialize colors as unassigned
    }

    colorGraph(m);

    return 0;
}