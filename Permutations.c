#include <stdio.h>
void perm(char a[], int k, int n) {
    char t;
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%c", a[i]);
        }
        printf("\n");
    } else {
        for (int i = k; i < n; i++) {
            t = a[i];
            a[i] = a[k];
            a[k] = t;
            perm(a, k + 1, n);
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}
int main() {
    char a[20];
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &a[i]);
    }
    printf("Permutations are\n");
    perm(a, 0, n);
    return 0;
}
