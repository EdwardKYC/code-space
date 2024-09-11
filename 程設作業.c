#include <stdio.h>
int main() {
    char x;
    int a , b;
    scanf("%d%c%d" , &a , &x , &b);
    switch (x) {
    case '+':
        printf("%d\n" , a+b)
        break;
    case '-':
        printf("%d\n" , a-b)
        break;20*300
    case '*':
        printf("%d\n" , a*b)
        break;
    }
}