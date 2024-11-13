#include <stdio.h>

int a[40];
int i,j;
int x,y;

void print() {
    for (j = 0; j < i; j++) {
        if (j == i - 1) {
            printf("%d\n", a[j]);
            break;
        }
        printf("%d ", a[j]);
    }
}

int main() {
    i = 0;
    do {
        scanf("%d", &a[i]);
        i++;
    } while (getchar() != '\n');
    do {
        scanf("%d", &a[i]);
        i++;
    } while (getchar() != '\n');
    for (x = 0; x < i-1; x++) {
        for (y = 0; y < i-1; y ++) {
            if (a[y] < a[y+1]) {
                int temp = a[y+1];
                a[y+1] = a[y];
                a[y] = temp;
            }
        }
    }
    for (x = 0; x < i-1; x++) {
        int c;
        while (a[x] == a[x+1] && x < i-1) {
            c = a[x];
            while (a[x] == c && x < i-1) {
                if (x == i-2 && a[x] == a[x+1]) {
                    i -= 2;
                    break;
                }
                for (y = x; y < i-1; y++) {
                    a[y] = a[y+1];
                }
                i--;
            }
        }
    }
    print();
    return 0;
}