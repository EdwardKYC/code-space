#include <stdio.h>

int main() {
    int n;
    scanf("%d" , &n);
    if (n == 1) {
        int x;
        scanf("%d" , &x);
        int bit[32];
        for (int i = 0; i < 32; i++) {
            bit[i] = x & 1;
            x >>= 1;
        }
        for (int i = 31; i >= 0; i--) {
            printf("%d" , bit[i]);
        }
    }
    else {

    }
    return 0;
}