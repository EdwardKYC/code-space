#include <stdio.h>
int main () {
    int n ;
    scanf("%d" , &n);
    if (n == 0)
        printf("NO");
    else if (n%2 != 0)
        printf("Yes");
    else 
        printf("NO");
    return 0;
}