#include <stdio.h>

int str[11] = {1,4,6,9,13,16,19,28,40,100,0};
int i, j;
int n;
int x;

int main() {
    scanf("%d", &x);
    getchar();
    n = 10;
    if (str[0] > x) {
        i = 0;
        for (j = n-1; j >= i; j--) {
            str[j+1] = str[j];
        }
        str[0] = x;
        goto END;
    }
    if (str[n-1] < x) {
        str[n] = x;
        goto END;
    }
    for (i = 0; i < n; i++) {
        if (str[i] <= x && x <= str[i+1]) {
            for (j = n-1; j > i; j--) {
                str[j+1] = str[j];
            }
            str[i+1] = x;
            break;
        }
    }
    END: for (i = 0; i < n+1; i++) {
        printf("%d ", str[i]);
    }
    return 0;
}