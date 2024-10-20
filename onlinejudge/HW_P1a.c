#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack stack;
struct stack{
    char *c;
    int top;
};
stack *ans;
void init(stack *k) {
    k -> top = -1;
    k -> c = (char *)malloc(100*sizeof(char));
}
void insert(stack *k , char s) {
    k -> c[++(k->top)] = s;
}
void pop(stack *k){
    if (k->top >= 0) {
        ans->c[++(ans->top)] = k->c[(k->top)];
        k->top--;
    }
    
}
void find(stack *k) {
    if (k->c[k->top] != '+'&&k->c[k->top] != '-'&&k->c[k->top] != '*'&&k->c[k->top] != '/'){
        pop(k);
        pop(k);
    }
}

int main () {
    char s[100];
    scanf("%s" , s);
    stack st;
    ans = (stack *)malloc(sizeof(stack)); 
    init(&st);
    init(ans);
    for (int i = 0; i < strlen(s); i++){
        insert(&st , s[i]);
        find(&st);
    }
    for(int i = 0; i <= ans->top; i++){
        printf("%c" , ans->c[i]);
    }
    printf("\n");
    return 0;
}