#include <stdio.h>

int i,x;
int n;
int q[999] = {1, 1, 1, 1};

int is(int a) {
    for (int y = 1; y <= n+1; y++) {
        if (a > y*(y-1)/2 && a <= y*(y+1)/2) {
            return y;
        }
    }
}

int main() {
    scanf("%d", &n);
    getchar();
    for (x = 4; x <= (n+2)*(n+1)/2; x++) {
        if (x == is(x)*(is(x)+1)/2 || x == is(x-1)*(is(x-1)+1)/2+1) {
            q[x] = 1;
            continue;
        }
        q[x] = q[x-is(x)] + q[x-is(x)+1];
    }
    for (x = 1; x <= (n+2)*(n+1)/2; x++) {
        for (i = 0; i < n - is(x) - 1; i++) {
            if (x == is(x-1)*(is(x-1)+1)/2+1 || x == 1) {
                printf("  ");
            }
        }
        printf("   %d", q[x]);
        if (x == is(x)*(is(x)+1)/2) {
            printf("\n");
        }
    }
    return 0;
}