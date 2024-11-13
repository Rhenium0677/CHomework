#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (str[j] > str[j+1]) {
                char tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < len-1; i++) {
        if (str[i] == str[i+1]) {
            for (int j = 0; j < len-i-1; j++) {
                str[i+j+1] = str[i+j+2];
            }
            len--;
        }
    }
}

void str_bin(char *str1, char *str2) {
    char *p = str1;
    while (*p != '\0') {
        p += 1;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        *p = str2[i];
        p += 1;
    }
    *p = '\0';
    sort(str1);
}

int main() {
    char *str1 = (char *) malloc(100 * sizeof(char));
    char *str2 = (char *) malloc(100 * sizeof(char));
    scanf("%s", str1);
    getchar();
    scanf("%s", str2);
    str_bin(str1, str2);
    printf("%s", str1);
    return 0;
}