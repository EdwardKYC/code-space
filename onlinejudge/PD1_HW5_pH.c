#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[2001][2001];

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a > b) ? b : a;
}
int main() {
    int n , m;
    scanf("%d %d" , &n , &m);  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d" , &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int max_m = 0;
        for (int j = 1; j <= m; j++) {
            max_m = max(max_m , a[i][j]);
        }
        a[i][0] = max_m;
    }
    for (int i = 1; i <= m; i++) {
        int max_n = 0;
        for (int j = 1; j <= n; j++) {
            max_n = max(max_n , a[j][i]);
        }
        a[0][i] = max_n;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += min(a[i][0] , a[0][j])-a[i][j];
        }
    }
    printf("%d" , ans);
    return 0;
}
