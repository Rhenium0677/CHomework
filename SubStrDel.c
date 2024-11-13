#include <stdio.h>

char a[100];
char b[100];
int i,j;
int x,y;

int len(char *x) {
    int count = 0;
    while (*x != '\0') {
        count++;
        x += sizeof(a[0]);
    }
    return count;
}
int is() {
    int count = 0;
    int w = x;
    while (a[w] == b[count] && count < j) {
        count++;
        w++;
    }
    if (count == j) {
        return 1;
    }
    return 0;
}

void print() {
    for (j = 0; j < i-1; j++) {
        printf("%c", a[j]);
    }
    printf("%c\n", a[i-1]);
}

int main() {
    scanf("%[^\n]", a);
    scanf(" %[^\n]", b);
    i = len(a);
    j = len(b);
    for (x = 0; x < i-j; x++) {
        while (is() == 1 && x < i-j) {
            for (y = x; y < i-j; y++) {
                a[y] = a[y+j];
            }
            i -= j;
        }
    }
    if (is() == 1 && x == i-j) {
        a[x] = '\0';
        i -= j;
    }
    print();
    return 0;
}