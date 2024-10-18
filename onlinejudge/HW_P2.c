#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct min_heap heap;
int endelement = 0;
struct min_heap 
{
    int data;
    heap *left;
    heap *right;
    heap *farther;
};
void upperfind(heap *c) {
    if(c->farther->data > c->data) {
        int temp = c->farther->data;
        c->farther->data = c->data;
        c->data = temp;
        upperfind(c->farther);
    }
}
void insert(heap *hp , int a){
    if (hp->farther == NULL && hp->left == NULL && hp->right == NULL) {
        hp->data = a;
        return;
    }
    if(hp->left ==NULL) {
        heap *newnode = (heap*)malloc(sizeof(heap));
        newnode->data = a;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->farther = hp;
        hp->left = newnode;
        upperfind(newnode);
    }
    else if (hp->right == NULL){
        heap *newnode = (heap *)malloc(sizeof(heap));
        newnode->data = a;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->farther = hp;
        hp->right = newnode;
        upperfind(newnode);
    }
    else if (hp->left->data <= a){
        insert(hp->left , a);
    }
    else if (hp->right->data <= a){
        insert(hp->right, a);
    }
    else
        insert(hp->left, a);
}
void find(heap *hp, int a){
    if (hp == NULL)return;
    if (hp->data == a){
        if (hp->farther != NULL){
            if (hp->farther->left == hp)hp->farther->left = NULL;
            if (hp->farther->right == hp)hp->farther->right = NULL;
        }
    }
}
void downfind(heap *hp) {
    if (hp->left != NULL && hp->left->data < hp->data) {
        int temp = hp->left->data;
        hp->left->data = hp->data;
        hp->data = temp;
        downfind(hp->left);
    }
    else if (hp->right != NULL && hp->right->data  < hp->data) {
        int temp = hp->right->data;
        hp->right->data = hp->data;
        hp->data = temp;
        downfind(hp->right);
    }
}
void delete(heap *hp , int a){
    if (hp == NULL)
        return;
    if (hp->data == a) {
        hp->data = endelement;
        downfind(hp);
    }
    else if (hp->data != a) {
        delete(hp->left , a);
        delete(hp->right , a);
    }
}
void ans(heap *hp) {
    if (hp == NULL)
        return;
    heap *queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = hp;
    while (front < rear) {
        heap *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL){
            queue[rear++] = current->left;
        }

        if (current->right != NULL){
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}
int main () {
    char *c = (char*)malloc(100*sizeof(char));
    char ins[] = "insert";
    char del[] = "delete";
    heap *hp = (heap *)malloc(sizeof(heap));
    hp->data = -1;
    hp->farther = NULL;
    hp->left = NULL;
    hp->right = NULL;
    while (fgets(c, 100, stdin) != NULL) {
        c[strcspn(c, "\n")] = '\0';
        char *c1 = strtok(c, " ");
        if (strcmp(c1, ins) == 0)
        {
            c1 = strtok(NULL, " ");
            int a = atoi(c1);
            endelement = a;
            insert(hp, a);
        }
        else if (strcmp(c1, del) == 0)
        {
            c1 = strtok(NULL, " ");
            int a = atoi(c1);
            find(hp, endelement);
            delete (hp, a);
        }
        
    }
    ans(hp);
    free(hp);
    free(c);
    return 0;
}