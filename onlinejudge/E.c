#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char add[2] = "+";
    char p[2] = ")";
    char str1[30] = "O(";
    char input[60];
    for (int i = 0; i < n; i++) {
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'f') {
            if (i != 0) {
                strcat(str1, add);
            }
        }
        for (int j = 0 ; j < strlen(input) ; j++) {
            if (input[j] == 'f') {
                char s_char[2] = {input[j+14], '\0'}; 
                strcat(str1, s_char);
                break;
            }      
        }
    }     
    strcat(str1, p);
    printf("%s", str1);
    return 0;
}