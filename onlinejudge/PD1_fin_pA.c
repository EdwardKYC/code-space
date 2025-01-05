#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct student {
    char name[100];
    bool used;
} student;

student s[100];
char result[100][100];
int n = 0;

void print_order() {
    for (int i = 0; i < n; i += 2) {
        printf("(%s, %s)", result[i], result[i + 1]);
        if (i + 2 < n) printf(", ");
    }
    printf("\n");
}

void order(int idx) {
    if (idx == n) { 
        print_order();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!s[i].used) {
            for (int j = i + 1; j < n; j++) {
                if (!s[j].used) {
                    s[i].used = s[j].used = true;
                    strcpy(result[idx], s[i].name);
                    strcpy(result[idx + 1], s[j].name);
                    order(idx + 2);
                    s[i].used = s[j].used = false;
                }
            }
        }
    }
}

int main() {
    while (scanf("%s", s[n].name) != EOF) {
        s[n++].used = false;
    }
    order(0);
    return 0;
}
