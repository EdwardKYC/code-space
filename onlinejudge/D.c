#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<math.h>
int main() {
    int n;
    scanf("%d" , &n);
    int x[n] , y[n];
    for (int i = 0 ; i < n; i++) {
        scanf("%d" , &x[i]);
    }
    for (int i = 0 ; i < n; i++) {
        scanf("%d" , &y[i]);
    }
    float A = 0 , B = 0 , C = 0;
    for (int i = 0 ; i < n; i++) {
        A += x[i]*y[i];
        B += x[i]*x[i];
        C += y[i]*y[i];
    }
    B = sqrt(B);
    C = sqrt(C);
    float ans = (A/(B*C));
    ans = ans*100;
    ans = floor(ans);
    ans /= 100;
    printf("%.2f" , ans);
    return 0;
}