#include <stdio.h>
#include <string.h>

void itoa(int a, char* b) {
    int i = 0;
    char index[] = "0123456789";
    do {
        b[i] = index[a % 10];
        a /= 10;
        i++;
    } while(a);
    b[i] = '\0';
    for (int j = 0; j <= i/2; j++) {
        char temp;
        temp = b[j];
        b[j] = b[i-j-1];
        b[i-j-1] = temp;
    }
}

int loop(int x) {
    char y[20];
    itoa(x, y);
    int len = strlen(y);
    for (int i = 0; i <= len / 2; i++) {
        if (y[i] != y[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (loop(i) == 1 && i % 2 == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}