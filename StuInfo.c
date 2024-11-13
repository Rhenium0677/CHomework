#include <stdio.h>
#include <stdlib.h>

struct student {
    int num;
    char name[10];
    int math;
    int eng;
    int chi;
    int sum;
    int rank;
};

void input(int *p) {
    scanf("%d", p);
    getchar();
}
void input_info(struct student *p, int len) {
    for (int i = 0; i < len; i++) {
        scanf("%d %s %d %d %d", &(p[i].num), p[i].name, &(p[i].math), &(p[i].eng), &(p[i].chi));
        getchar();
    }
}

void sum(struct student *p, int len) {
    for (int i = 0; i < len; i++) {
        p[i].sum = p[i].math + p[i].eng + p[i].chi;
    }
}
//get the total score of each student

void swap(struct student *p1, struct student *p2) {
    struct student temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void sort(struct student *p, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (p[j+1].sum < p[j].sum) {
                swap(p+j+1, p+j);
            }
            else if ((*(p+j+1)).sum == (*(p+j)).sum) {
                if (p[j+1].num < p[j].num) {
                    swap(p+j+1, p+j);
                }
            }
        }
    }
}
//sort according to the total score
void rank(struct student *p, int len) {
    int count = 0;
    for (int i = 1; count < len; count++) {
        p[len-count-1].rank = i;
        if (p[len-count-1].sum == p[len-count].sum && count > 0) {
            p[len-count-1].rank = p[len-count].rank;
        }
        i++;
        if (len-count-1 == 0) {
            break;
        }
    }
}
//rank each student

void print(struct student *p, int len) {
    for (int i = 0; i < len; i++) {
        printf("%4d%10d%10s%5d%5d%5d\n", p[i].rank, p[i].num, p[i].name, p[i].math, p[i].eng, p[i].chi);
    }
}
//output the result

int main() {
    int *len = (int *)malloc(sizeof(int));
    input(len);
    if (*len >= 10) {
        printf("Please input 1-9.");
        return 0;
    }
    struct student *info = (struct student *)malloc((*len) * sizeof(struct student));
    input_info(info, *len);
    sum(info, *len);
    sort(info, *len);
    rank(info, *len);
    print(info, *len);
    free(len);
    free(info);
    return 0;
}