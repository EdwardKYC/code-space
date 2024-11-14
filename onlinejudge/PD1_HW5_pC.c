#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define range 1000000

int time[range];
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int count , ans = 0;
    scanf("%d" , &count);
    int car_in[count] , car_out[count];
    for (int i = 0; i < count; i++) {
        scanf("%d %d" , &car_in[i] , &car_out[i]);
        time[car_in[i]-1]++;
        time[car_out[i]-1]--;
    }
    count = 0;
    for (int i = 0; i < range; i++) {
        count += time[i];
        ans = max(count , ans);
    }
    printf("%d" , ans);
    return 0;
}
