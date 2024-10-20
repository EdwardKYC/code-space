#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
int main() {
    int n;
    scanf("%d", &n);
    int point[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d" , &point[i][0] , &point[i][1]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 ; j--) {
            if (point[j][0] == point[j - 1][0]) {
                if (point[j][1] < point[j - 1][1]) {
                    int temp = point[j][0];
                    point[j][0] = point[j - 1][0];
                    point[j - 1][0] = temp;
                    int temp1 = point[j][1];
                    point[j][1] = point[j - 1][1];
                    point[j - 1][1] = temp1;
                }
            }
            else if (point[j][0] < point[j - 1][0]) {
                int temp = point[j][0];
                point[j][0] = point[j - 1][0];
                point[j - 1][0] = temp;
                int temp1 = point[j][1];
                point[j][1] = point[j - 1][1];
                point[j - 1][1] = temp1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", point[i][0] , point[i][1]);
    }
    return 0;
}
