#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

typedef struct FibNode {
    int key;
    int degree;
    bool mark;
    struct FibNode *parent;
    struct FibNode *child;
    struct FibNode *left;
    struct FibNode *right;
} FibNode;
FibNode initnode(int key) {
    FibNode newnode;
    newnode.parent = newnode.child = NULL;
    newnode.left = newnode.right = &newnode;
    newnode.key = key;
    newnode.degree = 0;
    newnode.mark = false;
    return newnode;
}

FibNode* insert(FibNode *node, int key) {
    FibNode* newnode = (FibNode*)malloc(sizeof(FibNode));
    *newnode = initnode(key);

    if (node->key == -1) *node = *newnode;
    else {
        newnode->right = node->right;
        newnode->left = node;
        node->right->left = newnode; 
        node->right = newnode;   
    }
    if (newnode->key < node->key) {
        *node = *newnode;
    }
    return node;
}

FibNode* extract_min(FibNode *node) {
    FibNode* minNode = node;
    FibNode* current = NULL;

    if (minNode->child != NULL) {
        current = minNode->child;
        do {
            current->parent = NULL; 
            current->mark = false;
            current = current->right; 
        } while (current != minNode->child); 

        minNode->left->right = minNode->child;
        minNode->child->left = minNode->left;

        minNode->child->left->right = minNode->right;
        minNode->right->left = minNode->child->left;
    }

    if (minNode->right == minNode) {
        FibNode* newnode = (FibNode*)malloc(sizeof(FibNode));
        *newnode = initnode(-1);
        free(minNode);
        return newnode;

    }
    else {
        minNode->left->right = minNode->right;
        minNode->right->left = minNode->left;
        node = minNode->right; 
    }

    current = node;
    do {
        if (current->key < node->key) {
            node = current; 
        }
        current = current->right;
    } while (current != node);

    free(minNode);
    node = consolidation(node);
    return node;
}
FibNode* consolidation(FibNode* node) {
    FibNode* degreeTable[100] = {NULL}; 
    FibNode* current = node;
    FibNode* next = NULL;
    do {
        next = current->right;
        int degree = current->degree;

        while (degreeTable[degree] != NULL) {
            FibNode* other = degreeTable[degree];
            if (current->key > other->key) {
                FibNode* temp = current;
                current = other;
                other = temp;
            }

            linkTrees(current, other);
            degreeTable[degree] = NULL;
            degree++;
        }

        degreeTable[degree] = current;
        current = next;
    } while (current != node);

    FibNode* minNode = NULL;
    for (int i = 0; i < 64; i++) {
        if (degreeTable[i] != NULL) {
            if (minNode == NULL || degreeTable[i]->key < minNode->key) {
                minNode = degreeTable[i];
            }
        }
    }

    return minNode;
}

void linkTrees(FibNode* parent, FibNode* child) {
    child->left->right = child->right;
    child->right->left = child->left;

    child->parent = parent;
    if (parent->child == NULL) {
        parent->child = child;
        child->left = child->right = child;
    } else {
        child->right = parent->child->right;
        child->left = parent->child;
        parent->child->right->left = child;
        parent->child->right = child;
    }

    parent->degree++;
    child->mark = false; 
}

FibNode* decrease(FibNode *node , int key , int value) {

}

int key , value;
int main() {
    FibNode node = initnode(-1);
    char command[20];
    while (1) {
        scanf("%s" , command);
        if (strcmp(command, "exit") == 0) {
            break;
        }
        else if (strcmp(command, "extract-min") == 0) {
            extract_min(&node);
        }
        else if (strcmp(command, "insert") == 0) {
            scanf("%d" , &key);
            insert(&node , key);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%d" , &key);
            decrease(&node , key , key);
            extract_min(&node);
        }
        else if (strcmp(command, "decrease") == 0) {
            scanf("%d %d" , &key , &value);
            decrease(&node , key , value);
        }
    }
    return 0;
}