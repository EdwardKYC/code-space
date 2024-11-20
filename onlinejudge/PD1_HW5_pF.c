#include <stdio.h>
#define ll long long int
int main() {
    int n , q , k;
    scanf("%d %d %d" , &n , &q , &k);
    ll p[n+1];
    for (int i = 1; i <= n; i++){
        int pi;
        scanf("%d" , &pi);
        pi = (pi < k) ? 1 : 0;
        p[i] = pi + p[i-1];
    }
    for (int i = 0; i < q; i++) {
        int begin , end;
        scanf("%d %d" , &begin , &end);
        printf("%d\n" , p[end] - p[begin - 1]);
    }
    return 0;
}