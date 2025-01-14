#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxnode 1000000
#define number 10

int trie[maxnode][number];
bool isEnd[maxnode];          
int n_cut = 1;              

void insert(const char* num) {
    int cur = 0;
    for (int i = 0; num[i]; i++) {
        int idx = num[i] - '0';
        if (!trie[cur][idx]) trie[cur][idx] = n_cut++;
        cur = trie[cur][idx];
    }
    isEnd[cur] = true;
}

bool search(const char* num) {
    int cur = 0;
    for (int i = 0; num[i]; i++) {
        int idx = num[i] - '0';
        if (!trie[cur][idx]) return false;
        cur = trie[cur][idx];
    }
    return isEnd[cur];
}

void delete(int cur, const char* num, int depth) {
    if (depth == strlen(num)) {
        isEnd[cur] = false;
        return;
    }
    int idx = num[depth] - '0';
    delete(trie[cur][idx], num, depth + 1);

    for (int i = 0; i < number; i++) {
        if (trie[cur][i]) return; 
    }
    if (!isEnd[cur]) trie[cur][idx] = 0; 
}

int main() {
    char cmd[10], key[15];
    while (scanf("%s", cmd) && strcmp(cmd, "exit")) {
        scanf("%s", key);
        if (!strcmp(cmd, "insert")) insert(key);
        else if (!strcmp(cmd, "delete")) delete(0, key, 0);
        else if (!strcmp(cmd, "search")) printf("%d\n", search(key));
    }
    return 0;
}
