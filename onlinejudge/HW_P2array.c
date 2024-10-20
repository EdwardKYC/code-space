#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
typedef struct {
    int data[1000]; 
    int size; 
} heap;

heap* init() {
    heap *hp = (heap*)malloc(sizeof(heap));
    hp->size = 0;
    return hp;
}

void upfind(heap *hp, int idx) {
    while (idx > 0) {
        int father = (idx - 1) / 2;
        if (hp->data[idx] < hp->data[father]) {
            int temp = hp->data[idx];
            hp->data[idx] = hp->data[father];
            hp->data[father] = temp;
            idx = father;
        } else {
            break;
        }
    }
}

void downfind(heap *hp, int idx) {
    while (2 * idx + 1 < hp->size) {
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int s = idx;
        if (hp->data[l] < hp->data[s]) {
            s = l;
        }
        if (r < hp->size && hp->data[r] < hp->data[s]) {
            s = r;
        }
        if (s != idx) {
            int temp = hp->data[idx];
            hp->data[idx] = hp->data[s];
            hp->data[s] = temp;
            idx = s;
        } else {
            break;
        }
    }
}

void insert(heap *hp, int a) {
    assert(hp->size < 1000); 
    hp->data[hp->size] = a;   
    upfind(hp, hp->size);     
    hp->size++;                
}

void delete(heap *hp, int a) {
    int idx = -1;
    for (int i = 0; i < hp->size; i++) {
        if (hp->data[i] == a) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return;  
    hp->data[idx] = hp->data[--hp->size]; 
    downfind(hp, idx);     
}

void ans(heap *hp) {
    for (int i = 0; i < hp->size; i++) {
        printf("%d ", hp->data[i]);
    }
    printf("\n");
}

void heap_free(heap *hp) {
    free(hp);
}

int main () {
    char *c = (char*)malloc(100 * sizeof(char));
    char ins[] = "insert";
    char del[] = "delete";
    heap *hp = init();
    
    while (fgets(c, 100, stdin) != NULL) {
        c[strcspn(c, "\n")] = '\0'; 
        char *c1 = strtok(c, " ");
        if (strcmp(c1, ins) == 0) {
            c1 = strtok(NULL, " ");
            int a = atoi(c1);
            insert(hp, a);
        } else if (strcmp(c1, del) == 0) {
            c1 = strtok(NULL, " ");
            int a = atoi(c1);
            delete(hp, a);
        }
    }
    ans(hp);
    heap_free(hp);
    free(c);

    return 0;
}
