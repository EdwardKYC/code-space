#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <windows.h>

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    int n , q;
    scanf("%d" , &n);
    int a[n+1]; 
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        int ai;
        scanf("%d" , &ai);
        a[i] = ai + a[i-1];
    }
    scanf("%d" , &q);
    for (int i = 0; i < q; i++) {
        int begin , end;
        scanf("%d %d" , &begin , &end);
        printf("%d\n" , a[end] - a[begin - 1]);
    }
    return 0;
}