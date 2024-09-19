#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char str1[200] , str2[100];
    scanf("%s %s" , str1 , str2);
    strcat(str1, str2);
    printf("%s\n" , str1);
    int a = 0;
    for (int i = 0 ; i < strlen(str1) ; i++) {
        if (i%2 == 0)
            a += str1[i];
        else if (i%2 != 0)
            a -= str1[i];
        else if (i == strlen(str1)-1 || a < 0)
            a = abs(a);
    }
    if (a % 11 == 0)
        printf("Yes");
    else    
        printf("No");
    return 0;
}