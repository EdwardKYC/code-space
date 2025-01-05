#include <stdio.h>
#include <stdlib.h>

int n;
typedef struct Node {
    int value;
    int idx;
    struct Node *pre;
} Node;
Node* creatnode(int key) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->value = key;
    newnode->idx = key;
    newnode->pre = NULL;
    return newnode;
}
Node* init(int n) {
    Node* node = creatnode(1);
    for (int i = 2; i <= n; i++) {
        Node* newnode = creatnode(i);
        newnode->pre = node;
        node = newnode;
    }
    return node;
}
Node* find(Node* node , int key) {
    while (node->value != key) {
        node = node->pre;
    }
    return node;
}
Node* anext(Node* node , int key) {
    while (node->pre->value != key) {
        node = node->pre;
    }
    return node;
}
Node* cut(Node* node , int a , int b) {
    Node* anextnode = anext(node , a);
    Node* rrr = find(node , b); //被插隊的
    Node* hahaha = find(node , a); //插人隊的
    anextnode->pre = hahaha->pre;
    hahaha->pre = rrr->pre;
    rrr->pre = hahaha;
    return node;
}
void printnode(Node *node , int q) {
    Node *temp = node;
    for (int i = 0; i < n-q; i++) {
        temp = temp->pre;
    }
    printf("%d\n" , temp->idx);
}
int main () {
    scanf("%d" , &n);
    Node* node = init(n);
    while(1) {
        int m;
        scanf("%d" , &m);
        if (m == 1) {
            int a , b;
            scanf("%d %d" , &a , &b);
            node = cut(node , a , b);
        } else if (m == 2) {
            int q;
            scanf("%d" , &q);
            printnode(node , q);
        } else {
            break;
        }
    }
    free(node);
    return 0;
}