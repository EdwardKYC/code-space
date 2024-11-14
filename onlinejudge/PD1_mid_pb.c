#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <windows.h>

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    int n , m;
    scanf ("%d %d\n" , &n , &m);
    char t[n];
    scanf ("%s\n" , t);
    int location;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'V')location = i;
    }

    for (int i = 0; i < m; i++) {
        char move;
        int movedistance , temp = location;
        scanf (" %c %d" , &move , &movedistance);
        if (move == 'L') temp -= movedistance;
        if (move == 'R') temp += movedistance;
        if (temp >= n || temp < 0) {
            printf("Out of range\n");
            continue;
        }
        t[location] = '.';
        t[temp] = 'V';
        location = temp;
        printf("%s\n" , t);
    }
    return 0;
}