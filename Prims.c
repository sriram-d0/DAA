#include <stdio.h>
#include <stdlib.h>

int prims(int cost[20][20], int n, int t[20][2]) {
    int mincost, min, i, j, k, near[20], l;
    mincost = min = 999;
    #Finding minimum cost edge among the graph
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (min > cost[i][j]) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    
    #creating spanning tree by initialising min cost edge vertices as first vertices
    t[1][1] = k;
    t[1][2] = l;
    
    #finding near vertices for each vertices if no direct edge then it is 9999(infinity)
    for (i = 1; i <= n; i++) {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    
    #as minimum cost vertices have no near vertices so assign it near[] as 0
    mincost = cost[k][l];
    near[k] = 0;
    near[l] = 0;
    int p, q;

    #finding near[i] to update spanning tree and find minimumm cost
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

        #now update spanning tree add cost of new edges to find minimum cost
        t[i][1] = p;
        t[i][2] = q;
        mincost += cost[p][q];
        near[p] = 0;

        #update near values for new spanning tree
        for (k = 1; k <= n; k++) {
            if (near[k] != 0 && cost[k][p] < cost[k][near[k]])
                near[k] = p;
        }
    }

    printf("Minimum Spanning Tree is\n");
    for (i = 1; i < n; i++) {
        printf("%d -> %d\n", t[i][1], t[i][2]);
    }

    return mincost;
}

int main() {
    int c[20][20], t[20][2], i, j, n, min;

    system("clear");
    printf("Enter no. of Nodes : ");
    scanf("%d", &n);

    printf("Enter Costs (0 for no direct edge)\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter cost between %d -> %d : ", i, j);
            scanf("%d", &c[i][j]);

            if (c[i][j] == 0) {
                c[i][j] = 9999;
            }
        }
    }

    min = prims(c, n, t);
    printf("The minimum cost is %d\n", min);

    return 0;
}
