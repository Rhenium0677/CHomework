#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a_len = 0;

void findint(char *s, int *a) {
    int *b = a;
    int len = strlen(s);
    char *p = s + len - 1;
    int i = len - 1;
    // use i to show where p points to
    int num;
    while (i >= 0) {
        num = *p - '0';
        if (num >= 0 && num <= 9) {
            *b = 0;
            for (int j = 0; num >= 0 && num <= 9; j++) {
                int pow = 1;
                for (int k = 0; k < j; k++) {
                    pow *= 10;
                }
                *b += num * pow;
                if (i == 0) {
                    num = 10;
                    break;
                }
                p--;
                i--;
                num = *p - '0';
            }
            //this 'for' gets a number and store it in array 'a'
            b++;
            a_len++;
        }
        if (i == 0) {
            if (num >= 0 && num <= 9) {
                continue;;
            }
            else {
                break;
            }
        }
        p--;
        i--;
    }
}

int main() {
    char *str = (char *) malloc(200 * sizeof(char));
    int *a = (int *) malloc(200 * sizeof(int));
    int i = 0;
    while((str[i++] = getchar()) != '\n');
    findint(str, a);
    for (int i = 0; i < a_len; i++) {
        if (i < a_len - 1) {
            printf("%d,", a[i]);
        }
        else {
            printf("%d\n", a[i]);
        }
    }
    free(str);
    free(a);
    return 0;
}