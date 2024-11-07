#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct max_heap heap;

struct max_heap {
    int data;
    heap *left;
    heap *right;
    heap *parent;
};
heap* creatnode(int data) {
    heap *newnode = (heap *)malloc(sizeof(heap));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}
void swap(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void upfind(heap *node) {
    heap *current = node;
    while (current->parent != NULL) {
        if (current->data > current->parent->data) {
            swap(&current->data , &current->parent->data);
            current = current->parent;
        }  
        else break;
    }
}
heap* insert(heap *node , int data) {
    if (node == NULL) return creatnode(data);
    int f = 0 , r = 0;
    heap **queue = (heap **) malloc(1000*sizeof(heap *)) ;
    queue[r++] = node;
    while (r > f) {
        heap *newnode = queue[f++];
        if (newnode->left == NULL) {
            newnode->left = creatnode(data);
            newnode->left->parent = newnode;
            upfind(newnode->left);
            break;
        }
        else if (newnode->right == NULL) {
            newnode->right = creatnode(data);
            newnode->right->parent = newnode;
            upfind(newnode->right);
            break;
        }
        else {
            queue[r++] = newnode->left;
            queue[r++] = newnode->right;
        }
    }
    free(queue);
    return node;
}
void downfind(heap *node) {
    heap *current = node;
    while (current->left != NULL || current->right != NULL) {
        if ((current->left != NULL && current->right != NULL) &&current->left->data > current->data && current->right->data > current->data) {
            current = (current->left->data > current->right->data)? current->left : current->right;
            swap(&current->data , &current->parent->data);
        }
        else if (current->left != NULL && current->left->data > current->data) {
            swap(&current->data , &current->left->data);
            current = current->left;
        }
        else if (current->right != NULL && current->right->data > current->data) {
            swap(&current->data , &current->right->data);
            current = current->right;
        }
        else{
            break;
        }
        
    }
}
heap* delete(heap *node , int data) {
    int f = 0 , r = 0;
    heap **queue = (heap **) malloc(1000*sizeof(heap *)) ;
    queue[r++] = node;
    while (r > f) {
        heap *newnode = queue[f++];
        if (newnode->left != NULL) queue[r++] = newnode->left;
        if (newnode->right != NULL) queue[r++] = newnode->right; 
    }
    heap *dnode = queue[--r];
    node->data = dnode->data;
    if (dnode->parent != NULL) {
        if (dnode->parent->left == dnode) {
            dnode->parent->left = NULL;
        } else if (dnode->parent->right == dnode) {
            dnode->parent->right = NULL;
        }
    }
    free(dnode);
    downfind(node);
    free(queue);
    return node;
}
void print(heap *node) {
    int f = 0 , r = 0;
    heap **queue = (heap **) malloc(1000*sizeof(heap *)) ;
    queue[r++] = node;
    while (r > f) {
        heap *newnode = queue[f++];
        printf("%d " , newnode->data);
        if (newnode->left != NULL) queue[r++] = newnode->left;
        if (newnode->right != NULL) queue[r++] = newnode->right; 
    }
    free(queue);
}
int main() {
    char option[10];
    int data;
    heap *root = NULL;
    
    while (scanf("%s" , option) != EOF) {
        scanf("%d" , &data);
        if (strcmp(option , "insert") == 0) {
            root = insert(root , data);
        }
        if (strcmp(option , "delete") == 0) {
            root = delete(root , data);
        }
    }
    print(root);
    return 0;
}