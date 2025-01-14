#include <stdio.h>
#include <string.h>

#define N 1000010

int son[N][26], cnt[N], idx = 0;

void insert(const char *str) {
    int p = 0; // 根節點
    for (int i = 0; str[i]; i++) {
        int t = str[i] - 'a'; // 將字符轉為相對應的 ASCII 編碼
        if (!son[p][t]) son[p][t] = ++idx; // 若此節點不存在，新增節點
        p = son[p][t]; // 移動到下一層
    }
    cnt[p]++; // 該節點為結尾的計數++
}

int query(const char *str) {
    int p = 0; // 根節點
    for (int i = 0; str[i]; i++) {
        int t = str[i] - 'a'; // 將字符轉為相對應的 ASCII 編碼
        if (!son[p][t]) return 0; // 查找不到，返回 0
        p = son[p][t]; // 移動到下一層
    }
    return cnt[p]; // 返回該節點的計數
}

int main() {
    int n;
    scanf("%d", &n); // 輸入操作數量

    while (n--) {
        char op[2], str[100];
        scanf("%s %s", op, str); // 輸入操作類型和字符串
        if (op[0] == 'I') {
            insert(str); // 插入
        } else if (op[0] == 'Q') {
            printf("%d\n", query(str)); // 查詢
        }
    }

    return 0;
}
