#include <stdio.h>
#define INFINITY_VALUE 99
void bford(int c[20][20], int v, int d[20], int n);
int main() {
    int c[20][20], d[20], n, v, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INFINITY_VALUE);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
            // Replace 0 with infinity for self-loops
            if (i == j && c[i][j] == 0) {
                c[i][j] = INFINITY_VALUE;
            }
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &v);

    bford(c, v, d, n);

    printf("Shortest distances from vertex %d:\n", v);
    for (i = 0; i < n; i++) {
        printf("Vertex %d: %d\n", i, d[i]);
    }

    return 0;
}
void bford(int c[20][20], int v, int d[20], int n) {
    int i, k, u, j;
    for (i = 0; i < n; i++) {
        d[i] = c[v][i];
    }
    for (k = 1; k <= n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (c[i][j] != INFINITY_VALUE && (d[j] > d[i] + c[i][j])) {
                    d[j] = d[i] + c[i][j];
                }
            }
        }
    }
}
