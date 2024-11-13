#include <stdio.h>

int power(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

void DigiTran(int k, char res[]) {
    int i = 0;
    while (k / power(10, i) != 0) {
        i++;
    }
    // i equals to the number of digits of k
    if (k == 0) {
        i = 1;
    }
    int j = i;
    int count = 0;
    // j equals to how many digits are still there to be operated
    // count equals to where the operation is in the array res[] and equals to the length of res[] at last
    while (j > 0) {
        if (k / power(10, j-2) <= 25 && j != 1) {
            res[count] = k / power(10, j-2) + 'A';
            k = k % power(10, j-2);
            j -= 2;
        }
        else {
            res[count] = k / power(10, j-1) + 'A';
            k = k % power(10, j-1);
            j--;
        }
        count++;
    }
    res[count] = '\0';
}

int main() {
    int num[200];
    int i = 0;
    while (num[i-1] != -1) {
        scanf("%d", &num[i]);
        getchar();
        i++;
    }
    int len = i-1;
    char res[200][20];
    for (i = 0; i < len; i++) {
        DigiTran(num[i], res[i]);
        printf("%s", res[i]);
        if (i != len - 1) {
            printf(" ");
        }
    }
    return 0;
}