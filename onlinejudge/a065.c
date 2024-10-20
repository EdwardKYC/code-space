#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
int main() {
    char c[7];
    scanf("%s", c);    
    char ans[7];
    for (int i =  0; i < 6; i++) {
        int a = (int)c[i] , b = (int)c[i+1];
        int p = a-b;
        p = abs(p);
        ans[i] = (char)(p + '0');
    }
    ans[6] = '\0';
    printf("%s\n" , ans);

    return 0;
}
