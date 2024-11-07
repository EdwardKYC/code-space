
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct stack
{
    int top;
    int data[100000];
}stack;
stack s;

int pop() {
    if (s.top > 0) return s.data[--s.top];
    return -1;
}
void intput(int n) {
    s.data[s.top++] = n;
}
bool push(char c[100]) {
    if (c[0] >= '0' && c[0] <= '9'){
        s.data[s.top++] = atoi(c);
    }
    else {
        int y = pop() , x = pop(); 
        if (x == -1 || y == -1) return false;

        if (strcmp(c, "+") == 0) intput(x+y);
        else if (strcmp(c, "-") == 0) intput(x-y);
        else if (strcmp(c, "*") == 0) intput(x*y);
        else if (strcmp(c, "/") == 0) intput(x/y);
    }
    return true;
}
int main() {
    s.top = 0;
    char c[100];
    bool f;
    while (scanf("%s" , c) != EOF) {
        f = push(c);
        if (!f)break;
    }
    int ans = pop();
    if (s.top != 0 || !f) printf("Invalid");
    else printf("%d" , ans);   
    return 0;
}