#include <stdio.h>

int jo[100];

void jsb(int p[], int d[], int n) {
    int i, j, temp;
    int max_dead = d[0];

    for (i = 0; i < n; i++) {
        jo[i] = i;
        if (d[i] > max_dead)
            max_dead = d[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i] < p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = jo[i];
                jo[i] = jo[j];
                jo[j] = temp;

                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    int seq[max_dead];

    for (i = 0; i < max_dead; i++) {
        seq[i] = -1;
    }

    int profit = 0;

    for (i = 0; i < n; i++) {
        for (j = d[i] - 1; j >= 0; j--) {
            if (seq[j] == -1) {
                seq[j] = jo[i];
                profit += p[i];
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (i = 0; i < max_dead; i++) {
        if (seq[i] != -1) {
            printf("J%d\t",seq[i] + 1);
        }
    }

    printf("\nProfit is %d\n", profit);
}

int main() {
    int i, n;
    system("clear");
    printf("Enter the number of profits and deadlines: ");
    scanf("%d", &n);
    int p[n], d[n];

    for (i = 0; i < n; i++) {
        printf("Enter p[%d]: ", i + 1);
        scanf("%d", &p[i]);
        printf("Enter d[%d]: ", i + 1);
        scanf("%d", &d[i]);
    }

    jsb(p, d, n);

    return 0;
}
