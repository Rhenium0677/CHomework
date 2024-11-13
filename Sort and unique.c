#include <stdio.h>
#include <string.h>

char str[50];
int size;
int i, j;
int n;
int x;

int main() {
    scanf("%s", str);
    getchar();
    size = strlen(str);
    n = size;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size - 1; j++) {
            if (str[j] > str[j+1]) {
                x = str[j+1];
                str[j+1] = str[j];
                str[j] = x;
            }
        }
    }
    for (i = 0; i < n; i++) {
        while (str[i] == str[i+1]) {
            for (j = i; j <= size - 1; j++) {
                str[j] = str[j+1];
            }
            n--;
        }
    }
    printf("%s", str);
    return 0;
}