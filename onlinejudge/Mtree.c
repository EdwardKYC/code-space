#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
typedef struct Mtree{
    int *keys;
    struct Mtree **child;
    int num_key;
    bool isleaf;
}Mtree;
int m;
int compareKeys(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
Mtree* init(int k) {
    Mtree *newnode = (Mtree*)malloc(sizeof(Mtree));
    newnode->isleaf = false;
    newnode->num_key = 1;
    newnode->keys = (int *)malloc((m-1)*sizeof(int));
    newnode->child = (Mtree**)malloc(m*sizeof(Mtree*));
    for (int i = 0; i < m; i++) newnode->child[i] = NULL;
    newnode->keys[0] = k;
    return newnode;
}
Mtree* insert(Mtree* node , int k) {
    if (node == NULL) {
        node = init(k);
        return node;
    }
    else if (node->num_key + 1 == m) {
        for (int i = 0; i < node->num_key; i++) {
            if (k < node->keys[i]) {
                node->child[i] = insert(node->child[i] , k);
                return node;
            }
        }
        node->child[m-1] = insert(node->child[m-1] , k);
        return node;
    }
    else {
        node->num_key++;
        node->keys[node->num_key-1] = k;
        qsort(node->keys, node->num_key, sizeof(int), compareKeys); 
        return node;
    }
}
Mtree* delete(Mtree* node , int k) {

}
void print_level(Mtree *node) {
    for (int i = 0; i < node->num_key; i++) {
        if (node->child[i] != NULL) print_level(node->child[i]);
        if (node->keys[i] != -1) printf("%d " , node->keys[i]);
    }
    if (node->child[node->num_key] != NULL) print_level(node->child[node->num_key]);
}
int main() {
    int opt , k;
    scanf("%d" , &m);
    Mtree *node = NULL;
    while (scanf("%d" , &opt) != EOF) {
        if (opt == 3) break;
        scanf("%d" , &k);
        if (opt == 1) {
            node = insert(node , k);
        }
        else if  (opt == 2) {
            node = delete(node , k);
        }
       
    }
    print_level(node);
    return 0;
}