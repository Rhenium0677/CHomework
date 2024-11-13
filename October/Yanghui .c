#include <stdio.h>

int q[13][13];
int i, j, n, x;

int main() {
    scanf("%d", &n);
    q[0][0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                q[i][j] = 1;
            }
            else {
                q[i][j] = q[i-1][j-1] + q[i-1][j];
            }
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n-i; j++) {
            printf("  ");
        }
        for (j = 0; j <= i; j++) {
            printf("%4.d", q[i][j]);
        }
        printf("\n");
    }
    return 0;
}