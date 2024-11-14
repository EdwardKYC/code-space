#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
bool check(int data){
    if (data <= 60 && data >= 40) return true;
    return false;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;   
    scanf("%d" , &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d" , &a[i]);
    }
    int k = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (check(a[i]) && k == 0) {
            ans++;
            k = 1;
        }
        if (!check(a[i])) k = 0;
    }
    printf("%d" , ans);
    return 0;
}