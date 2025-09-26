#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int key;
    void *value;
    Color color;
    struct RBNode *left, *right, *parent;
} RBNode;

typedef struct {
    RBNode *root;
    RBNode *nil;
} RBTree;

// ====== 基本節點與旋轉函式 ======

RBNode* create_node(RBTree *tree, int key, void *value) {
    RBNode *node = (RBNode *)malloc(sizeof(RBNode));
    node->key = key;
    node->value = value;
    node->color = RED;
    node->left = node->right = node->parent = tree->nil;
    return node;
}

void left_rotate(RBTree *tree, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != tree->nil) y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == tree->nil) tree->root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void right_rotate(RBTree *tree, RBNode *y) {
    RBNode *x = y->left;
    y->left = x->right;
    if (x->right != tree->nil) x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == tree->nil) tree->root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;

    x->right = y;
    y->parent = x;
}

void insert_fixup(RBTree *tree, RBNode *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    left_rotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent);
            }
        } else {
            RBNode *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

// ====== Map 功能 ======

void rb_insert(RBTree *tree, int key, void *value) {
    RBNode *z = create_node(tree, key, value);
    RBNode *y = tree->nil;
    RBNode *x = tree->root;

    while (x != tree->nil) {
        y = x;
        if (key == x->key) {
            // 若已存在 key，更新 value 並釋放 z
            x->value = value;
            free(z);
            return;
        } else if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == tree->nil)
        tree->root = z;
    else if (key < y->key)
        y->left = z;
    else
        y->right = z;

    z->left = z->right = tree->nil;
    insert_fixup(tree, z);
}

void* rb_search(RBTree *tree, int key) {
    RBNode *x = tree->root;
    while (x != tree->nil) {
        if (key == x->key)
            return x->value;
        else if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return NULL;
}

RBTree* create_tree() {
    RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
    tree->nil = (RBNode *)malloc(sizeof(RBNode));
    tree->nil->color = BLACK;
    tree->nil->left = tree->nil->right = tree->nil->parent = NULL;
    tree->root = tree->nil;
    return tree;
}

// 中序列印 key-value（假設 value 是字串）
void inorder_print(RBTree *tree, RBNode *node) {
    if (node != tree->nil) {
        inorder_print(tree, node->left);
        printf("%d => %s\n", node->key, (char *)node->value);
        inorder_print(tree, node->right);
    }
}

int main() {
    RBTree *tree = create_tree();

    rb_insert(tree, 10, "apple");
    rb_insert(tree, 20, "banana");
    rb_insert(tree, 5, "grape");
    rb_insert(tree, 15, "mango");
    rb_insert(tree, 5, "updated_grape"); // update test

    inorder_print(tree, tree->root);

    int key = 5;
    char *result = (char *)rb_search(tree, key);
    if (result)
        printf("Found: key %d => %s\n", key, result);
    else
        printf("Key %d not found.\n", key);

    return 0;
}
