#include <stdio.h>
int prim(int cost[10][10], int n, int t[10][2]) {
    int mincost, min, p, q, k, l, i, j;
    int near[10];

    min = 9999;

    // Find the minimum cost edge and store its vertices in k and l
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (min > cost[i][j]) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    // Initialize the first edge of the minimum spanning tree
    t[1][1] = k;
    t[1][2] = l;

    for (i = 1; i <= n; i++) {
        // Determine the nearest neighbor for each node
        if (cost[i][k] < cost[i][l]) {
            near[i] = k;
        } else {
            near[i] = l;
        }
    }

    mincost = cost[k][l];
    near[k] = 0;
    near[l] = 0;

    for (i = 2; i < n; i++) {
        min = 9999;

        for (j = 1; j <= n; j++) {
            if (near[j] != 0) {
                if (min > cost[j][near[j]]) {
                    min = cost[j][near[j]];
                    p = j;
                    q = near[j];
                }
            }
        }

        // Add the edge with minimum cost to the minimum spanning tree
        t[i][1] = p;
        t[i][2] = q;
        mincost += cost[p][q];
        near[p] = 0;

        for (k = 1; k <= n; k++) {
            // Update nearest neighbors if a shorter edge is found
            if (near[k] != 0 && cost[k][p] < cost[k][near[k]]) {
                near[k] = p;
            }
        }
    }

    // Output the minimum spanning tree
    printf("Minimum Spanning Tree is:\n");
    for (i = 1; i < n; i++) {
        printf("%d -- %d\n", t[i][1], t[i][2]);
    }

    return mincost;
}

int main() {
    int cost[10][10], t[10][2], min;
    int i, j, n;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the costs of edges
    printf("Enter costs (0 for no direct edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter cost between %d and %d: ", i, j);
            scanf("%d", &cost[i][j]);

            // Treat 0 cost as a very high cost (9999) for no direct edge
            if (cost[i][j] == 0) {
                cost[i][j] = 9999;
            }
        }
    }

    // Calculate the minimum spanning tree using Prim's algorithm
    min = prim(cost, n, t);

    // Output the minimum cost
    printf("The minimum cost is %d\n", min);

    return 0;
}



