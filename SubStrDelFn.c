#include <stdio.h>
#include <string.h>

char a[100];
char b[100];
int i,j;
int x,y;
char ch;

int main() {
    scanf("%[^\n]", a);
    i = 0;
    getchar();
    while ((ch = getchar()) != '\n' && ch != EOF) {
        b[i++] = ch;
    }
    b[i] = '\0';
    i = strlen(a);
    j = strlen(b);
    if (b[0] == ' ') {
        for (x = 0; x < i-j; x++) {
            if (a[x] == ' ') {
                for (y = x; y < i-j; y++) {
                    a[y] = a[y+j];
                }
                i -= 1;
            }
        }
        a[i] = '\0';
        goto END;
    }
    int count = 0;
    char *p;
    char t[100];
    while ((p = strstr(a, b)) != NULL && count < i) {
        strcpy(t, p+j);
        *p = '\0';
        strcat(a, t);
        i -= j;
        count ++;
    }
    END: printf("%s", a);
    return 0;
}