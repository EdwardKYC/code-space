#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <windows.h>
typedef struct Node
{
    int value;
    struct Node *next;
}Node;
Node* init(int key) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->value = key;
    return newnode;
}
void push_back(int p , Node* node) {
    if (node->value == -1) {
        node->value = p;
        return;
    }
    Node* temp = node;
    while (temp->next != NULL) temp = temp->next;
    temp->next = init(p);
}
bool find(int p , Node* node) {
    if (node->value == -1) return false;
    Node* temp = node;
    while (temp->value != p) {
        if (temp->next == NULL) return false;
        temp = temp->next;
    }
    return true;
}
void kick(int q, Node* node) {
    Node* temp = node;
    Node* prev = NULL; 

    while (temp != NULL && temp->value == q) {
        Node* toDelete = temp;
        temp = temp->next;   
        free(toDelete);   
        node = temp;        
    }
    while (temp != NULL) {
        if (temp->value == q) {
            Node* toDelete = temp;
            prev->next = temp->next; 
            free(toDelete);          
            temp = prev->next;    
        } else {
            prev = temp;   
            temp = temp->next; 
        }
    }

    if (node == NULL) node = init(-1);
}
void link(Node** g1, Node** g2) {
    if ((*g1)->value == -1) return;
    if ((*g2)->value == -1) {
        *g2 = *g1;
        return;
    }
    Node* temp = *g2;
    while (temp->next != NULL) temp = temp->next;
    temp->next = *g1;
}
void print(Node* node) {
    if (node->value == -1) printf("Empty\n");
    else {
        while (node != NULL) {
            printf("%d " , node->value);
            node = node->next;
        }
        printf("\n");
    }
    return;
}
int main() {
    //SetConsoleOutputCP(CP_UTF8);
    int q;
    scanf("%d" , &q);
    int opt , g , p;
    Node *queue[10];
    for (int i = 0; i < 10; i++) queue[i] = init(-1);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d" , &opt , &g , &p);
        if (opt == 1) {
            push_back(p , queue[g-1]);
        }
        else if (opt == 2 && find(p , queue[g-1])) {
            kick(p , queue[g-1]);
        }
        else if (opt == 3) {
            link(&queue[g-1] , &queue[p-1]);
            queue[g-1] = init(-1);
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("Team%d: " , i+1);
        print(queue[i]);
    }
    return 0;
}
    