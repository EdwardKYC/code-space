#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
typedef struct min_heap heap;
struct min_heap {
    int data;
    heap *left;
    heap *right;
    heap *farther;
};
heap* init(int a) {
    heap *hp = (heap *)malloc(sizeof(heap));
    hp->data = a;
    hp->left = NULL;
    hp->right = NULL;
    hp->farther = NULL;
    return hp;
}
void upfind(heap *node) {
    assert(node != NULL);
    while (node->farther != NULL && node->data < node->farther->data) {
        int temp = node->data;
        node->data = node->farther->data;
        node->farther->data = temp;
        node = node->farther;
    }
}
void downfind(heap *node) {
    assert(node != NULL);
    while (node->left != NULL || node->right != NULL) {
        heap *smallest = node;
        if (node->left != NULL && node->left->data < smallest->data)  smallest = node->left;
        if (node->right != NULL && node->right->data < smallest->data)  smallest = node->right;
        if (smallest == node) break;
        int temp = node->data;
        node->data = smallest->data;
        smallest->data = temp;
        node = smallest;
    }
}
void insert(heap *hp , int a) {
    assert(hp != NULL);
    heap *newnode = init(a);
    heap *queue[1000];
    int find = 0, idx = 0;
    queue[idx++] = hp;
    if (hp->data == -1) {
        hp->data = a;
        return;
    }
    while (find < idx) {
        heap *now = queue[find++];
        assert(now != NULL);
        if (now->left == NULL) {
            now->left = newnode;
            newnode->farther = now;
            break;
        }
        else if (now->right == NULL) {
            now->right = newnode;
            newnode->farther = now; 
            break;
        }
        queue[idx++] = now->left;
        queue[idx++] = now->right;
    }
    upfind(newnode);
}
void delete(heap *hp , int a) {
    assert(hp != NULL);
    heap *queue[1000]; 
    int find = 0, idx = 0;
    queue[idx++] = hp;
    heap *del = NULL;
    heap *last = NULL;
    while (find < idx) {
        heap *now = queue[find++];
        assert(now != NULL);
        if (now->left != NULL) {
            queue[idx++] = now->left;
            last = now->left;
        }
        if (now->right != NULL) {
            queue[idx++] = now->right;
            last = now->right;
        }
        if (now->data == a) del = now;
    }
    if (del == hp && last == NULL) {
        hp->data = -1; 
        return;
    }
    if (del == last) {
        if (last->farther != NULL) {
            if (last->farther->left == last) last->farther->left = NULL;
            else if (last->farther->right == last) last->farther->right = NULL;
        }
        free(last);
        return;
    }
    del->data = last->data;
    if (last->farther != NULL) {
        if (last->farther->left == last) last->farther->left = NULL;
        else if (last->farther->right == last) last->farther->right = NULL;
    }
    downfind(del);
    free(last);
}
void ans(heap *hp) {
    heap *queue[1000];
    int find = 0, idx = 0;
    queue[idx++] = hp;
    while (find < idx) {
        heap *now = queue[find++];
        assert(now != NULL);
        printf("%d ", now->data);
        if (now->left != NULL) queue[idx++] = now->left;
        if (now->right != NULL) queue[idx++] = now->right;

    }
    printf("\n");
}
void hp_free(heap *hp) {
    if (hp == NULL) return;
    hp_free(hp->left);
    hp_free(hp->right);
    free(hp);
}
int main () {
    char *c = (char*)malloc(100*sizeof(char));
    char ins[] = "insert";
    char del[] = "delete";
    heap *hp = init(-1);
    while (fgets(c, 100, stdin) != NULL) {
        c[strcspn(c, "\n")] = '\0';
        char *c1 = strtok(c, " ");

        if (strcmp(c1, ins) == 0) {
            c1 = strtok(NULL, " ");
            int a = atoi(c1);
            insert(hp, a);
        }
        else if (strcmp(c1, del) == 0) {
            c1 = strtok(NULL, " ");
            int a = atoi(c1);
            delete (hp, a);
        }
    }
    ans(hp);
    hp_free(hp);
    free(c);
    return 0;
}
