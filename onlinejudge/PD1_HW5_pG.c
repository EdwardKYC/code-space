#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
int funtion(int x , int y , int z){
    return (((x + z) ^ (y - z)) - (x & z & (y & 2024) | abs(z - y)));
}
int max (int a, int b) {
    return (a > b) ? a : b;
}
int main() {

    int a , b , c;
    scanf("%d %d %d" , &a , &b , &c);
    int ans = INT_MIN;
    ans = max(ans , funtion(a , b , c));
    ans = max(ans , funtion(a , c , b));
    ans = max(ans , funtion(b , a , c));
    ans = max(ans , funtion(b , c , a));
    ans = max(ans , funtion(c , b , a));
    ans = max(ans , funtion(c , a , b));
    printf("%d" , ans);
    return 0;
}