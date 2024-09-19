#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char str1[100] = "O(";
    char input[100];
    int addPlus = 0; // 用來標記是否需要在下一個變數前添加 '+'

    for (int i = 0; i < n; i++) {
        fgets(input, sizeof(input), stdin);

        // 檢查行首是否為空白（即是否有縮排）
        if (input[0] == ' ') {
            // 行首是空白，這意味著需要在變數之前添加 '+'
            if (addPlus) {
                strcat(str1, "+");
            }
        } else {
            // 行首不是空白
            if (strlen(str1) > 2) { // 當 'O(' 和後面變數之間已有內容時
                strcat(str1, "+"); // 前面已經有內容，添加 '+'
            }
        }

        // 提取變數
        for (int j = 0; j < strlen(input); j++) {
            if (input[j] == 'f') {
                char s_char[2] = {input[j+14], '\0'};
                strcat(str1, s_char);
                addPlus = 1; // 設置需要 '+' 標記
                break;
            }
        }
    }

    strcat(str1, ")");
    printf("%s\n", str1);

    return 0;
}