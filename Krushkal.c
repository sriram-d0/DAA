#include <stdio.h>

// Function prototypes
void kruskal(int cost[10][10], int n, int t[10][2]);
void Union(int u, int v);
int find(int i);
void sort(int a[10], int n);
int id[10];
int main() {
    int cost[10][10], t[10][2], i, j, n;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the costs of edges
    printf("Enter cost of edges:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter cost from node %d to node %d: ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n, t);

    // Output the minimum spanning tree
    printf("Minimum Spanning Tree Edges:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j <= 2; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void kruskal(int cost[10][10], int n, int t[10][2]) {
    int x, y, b = 0, a[50], i, j, g, k, u, v, mincost = 0, m = 1, s = 1, p;

    // Store non-zero edge costs in an array
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cost[i][j] != 0) {
                a[b++] = cost[i][j];
            }
        }
    }

    // Sort the edge costs
    sort(a, b);

    // Initialize the disjoint-set data structure
    for (i = 1; i <= n; i++) {
        id[i] = -1;
    }

    while (m < n) {
        g = a[0];
        s = 1;

        // Find the next edge with the minimum cost
        for (i = 1; i <= n && s; i++) {
            for (j = 1; j <= n && s; j++) {
                if (cost[i][j] == g) {
                    u = i;
                    v = j;
                    cost[i][j] = cost[j][i] = 0;
                    s = 0;
                }
            }
        }

        b = b - 2;

        // Remove the processed edge from the array
        for (p = 0; p < b; p++) {
            a[p] = a[p + 2];
        }

        x = find(u);
        y = find(v);

        // Check if adding the edge forms a cycle
        if (x != y) {
            t[m][1] = u;
            t[m][2] = v;
            mincost += g;
            Union(x, y);
            m++;
        }
    }

    printf("Minimum cost is %d\n", mincost);
}
void Union(int u, int v) {
    // Perform union operation to merge sets
    id[u] = v;
}

int find(int i) {
    // Find the root of a set
    while (id[i] >= 0) {
        i = id[i];
    }
    return i;
}
void sort(int a[10], int n) {
    // Simple sorting function (e.g., bubble sort)
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

