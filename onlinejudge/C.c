#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d" , &n);
    int *array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = i+1;
    }
    int m , a , b , p;
    while(scanf("%d" , &m)) {
        if (m == 1) {
            scanf("%d %d" , &a , &b);
            
            int bp , ap;
            for (bp = 0; bp < n; bp++) {
                if (array[bp] == b) break;
            }
            for (ap = 0; ap < n; ap++) {
                if (array[ap] == a) break;
            }
            if (ap < bp) {
                for (int i = ap; i < bp; i++) {
                array[i] = array[i + 1];
            }
            array[bp - 1] = a;
            }
            else {
                for (int i = ap; i > bp; i--) {
                array[i] = array[i - 1];
            }
            array[bp] = a;
            }
            
        }
        else if (m == 2) {
            scanf("%d", &p);
            printf("%d\n", array[p - 1]);
        }
        else
            break; 
    }
    return 0;
}