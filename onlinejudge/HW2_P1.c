#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define MAX_BUCKET 100
#define MAX_SLOT 20

int n , m;
int hashTable[MAX_BUCKET][MAX_SLOT];

void insert(int key) {
    int h = key % n;
    while (1) {
        for (int i = 0; i < m; i++) {
            if (hashTable[h][i] == -1) {
                hashTable[h][i] = key;
                return;
            }
        }
        
        h = (h + 1) % n;
    }
}
void search(int key) {
    int h = key % n;
    while (1) {
        for (int i = 0; i < m; i++) {
            if (hashTable[h][i] == key) {
                printf("%d %d\n" , h, i);
                return;
            }
        }
        h = (h + 1) % n;
    }
}
void delete(int key) {
    int h = key % n;
    while (1) {
        for (int i = 0; i < m; i++) {
            if (hashTable[h][i] == key) {
                hashTable[h][i] = -1;
                return;
            }
        }
        h = (h + 1) % n;
    }
}
int main() {
    char temp1[20] , temp2[20];
    scanf("%s %d" ,temp1 , &n);
    scanf("%s %d" ,temp2 , &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            hashTable[i][j] = -1;
        }
    }

    char c[20]; int key;
    while (1) {
        scanf("%s", c);
        if (strcmp(c , "exit") == 0) break;
        else if (strcmp(c , "insert") == 0) {
            scanf("%d", &key);
            insert(key);
        }
        else if (strcmp(c , "search") == 0) {
            scanf("%d", &key);
            search(key);
        }
        else if (strcmp(c , "delete") == 0) {
            scanf("%d", &key);
            delete(key);
        }
    }
    return 0;
}