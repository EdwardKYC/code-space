#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <windows.h>

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    char c[10];
    scanf("%s" , c);
    int inp = 0;
    for (int i = 0; i < strlen(c); i++) {
        char temp = c[i];
        c[i] = 'a';
        int find = 1;
        for (int j = 0 , k = strlen(c)-1; j < k; j++ , k--) {
            if (c[j] == 'a') j++;
            else if (c[k] == 'a') k--;
            if (c[k] != c[j]) find = 0;
        }
        c[i] = temp;
        if (find == 1) {
            printf ("%d " , i+1);
            inp = 1;
        }
    }
    if (inp == 0) {
        printf ("Impossible");
    }
    return 0; 
}
