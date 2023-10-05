#include <stdio.h>

int p[100], w[100], jo[100], n;
float pw[100], x[100];

void knapsack(int m, int n) {
    float t1;
    int i, j, t3;
    float profit = 0; // Initialize profit to 0

    // Sort items based on profit-to-weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pw[i] < pw[j]) {
                t1 = pw[i];
                pw[i] = pw[j];
                pw[j] = t1;
                t3 = p[i];
                p[i] = p[j];
                p[j] = t3;
                t3 = w[i];
                w[i] = w[j];
                w[j] = t3;
                t3 = jo[i];
                jo[i] = jo[j];
                jo[j] = t3;
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = 0;
        int u = m;
        for (j = 0; j < n; j++) { // Removed the extra semicolon here
            if (w[j] > u)
                break;
            x[j] = 1;
            u = u - w[j];
        }
        if (j < n) {
            x[j] = (float)u / w[j];
            u = u - w[i];
        }
    }

    // Calculate profit and print the sequence
    for (i = 0; i < n; i++) {
        profit += p[i] * x[i];
        printf("%d  ", jo[i]);
    }
    printf("profit=%f\n", profit);
}

int main() {
    int i, n, m;
    printf("Enter the number of objects (n): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter p%d: ", i + 1);
        scanf("%d", &p[i]);
        printf("Enter w%d: ", i + 1);
        scanf("%d", &w[i]);
        jo[i] = i + 1;
    }

    printf("Enter Knapsack Capacity (m): ");
    scanf("%d", &m);
    knapsack(m, n);

    return 0;
}

