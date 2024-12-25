#include<stdio.h>
#include<stdlib.h>
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
void printTreeLevel(FibNode* root) {
    if (!root) return;
    FibNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            FibNode* current = queue[front++];
            printf("%d ", current->key);
            FibNode* child = current->child;
            if (child) {
                FibNode* temp = child;
                do {
                    queue[rear++] = temp;
                    temp = temp->right;
                } while (temp != child);
            }
        }
    }
    printf("\n");
}
int compareDegree(const void* a, const void* b) {
    FibNode* nodeA = *(FibNode**)a;
    FibNode* nodeB = *(FibNode**)b;
    if (nodeA->degree != nodeB->degree) {
        return nodeA->degree - nodeB->degree;
    }
    return nodeA->key - nodeB->key;
}
void printLevelOrder(FibNode* node) {
    if (!node || node->key == -1) return;

    int count = 0;
    FibNode* current = node;
    do {
        count++;
        current = current->right;
    } while (current != node);

    FibNode** rootList = (FibNode**)malloc(count * sizeof(FibNode*));
    current = node;
    for (int i = 0; i < count; i++) {
        rootList[i] = current;
        current = current->right;
    }
    qsort(rootList, count, sizeof(FibNode*), compareDegree);
    for (int i = 0; i < count; i++) {
        printTreeLevel(rootList[i]);
    }

    free(rootList);
}
FibNode* initnode(int key) {
    FibNode* newnode = (FibNode*)malloc(sizeof(FibNode));
    newnode->parent = newnode->child = NULL;
    newnode->left = newnode->right = newnode; 
    newnode->key = key;
    newnode->degree = 0;
    newnode->mark = false;
    return newnode;
}
FibNode* insert(FibNode *node, int key) {
    FibNode* newnode = (FibNode*)malloc(sizeof(FibNode));
    *newnode = initnode(key);

    if (node->key == -1) *node = *newnode;x
    else {
        newnode->right = node->right;
        newnode->left = node;
        node->right->left = newnode; 
        node->right = newnode;   

        if (newnode->key < node->key) {
            node = newnode; 
        }
    }
    return node;
}
FibNode* findNode(FibNode* node, int key) {
    FibNode* current = node;
    if (current == NULL) return NULL;
    do {
        if (current->key == key) {
            return current;
        }
        if (current->child) {
            FibNode* found = findNode(current->child, key);
            if (found) return found;
        }
        current = current->right;
    } while (current != node);
    return NULL;
}
void cut(FibNode* min, FibNode* x, FibNode* y) {
    if (x->right == x) {
        y->child = NULL;
    } else {
        x->left->right = x->right;
        x->right->left = x->left;
        if (y->child == x) {
            y->child = x->right;
        }
    }
    y->degree--;
    x->left = min;
    x->right = min->right;
    min->right->left = x;
    min->right = x;
    x->parent = NULL;
    x->mark = false;
}
void cascadingCut(FibNode* min, FibNode* y) {
    FibNode* z = y->parent;
    if (z != NULL) {
        if (!y->mark) {
            y->mark = true;
        } else {
            cut(min, y, z);
            cascadingCut(min, z);
        }
    }
}
FibNode* decrease(FibNode* node, int key, int value) {
    FibNode* target = findNode(node, key);
    if (!target) return node;
    target->key -= value;
    FibNode* parent = target->parent;
    if (parent && target->key < parent->key) {
        cut(node, target, parent);
        cascadingCut(node, parent);
    }
    if (target->key < node->key) {
        node = target;
    }
    return node;
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
FibNode* consolidation(FibNode* node) {
    FibNode* degreeTable[64] = {NULL};
    FibNode* current = node;
    FibNode* next;
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
            if (minNode == NULL) {
                degreeTable[i]->left = degreeTable[i]->right = degreeTable[i];
                minNode = degreeTable[i];
            } else {
                FibNode* tail = minNode->left;
                tail->right = degreeTable[i];
                degreeTable[i]->left = tail;
                degreeTable[i]->right = minNode;
                minNode->left = degreeTable[i];

                if (degreeTable[i]->key < minNode->key) {
                    minNode = degreeTable[i];
                }
            }
        }
    }
    return minNode;
}
FibNode* minrootnode(FibNode* node) {
    FibNode* current = node;
    FibNode* minNode = node; 
    do {
        if (current->key < minNode->key) {
            minNode = current; 
        }
        current = current->right; 
    } while (current != node); 

    return minNode; 
}
FibNode* extract_min(FibNode* node) {
    FibNode* minNode = node;
    if (!minNode) return NULL;
    FibNode* current = minNode->child;
    if (current != NULL) {
        do {
            current->parent = NULL;
            current = current->right;
        } while (current != minNode->child);
        FibNode* minLeft = minNode->left;
        FibNode* childLeft = minNode->child->left;

        minLeft->right = minNode->child;
        minNode->child->left = minLeft;

        childLeft->right = minNode->right;
        minNode->right->left = childLeft;
        node = minrootnode(minNode->child);
        
    } else {
        if (minNode->right == minNode) {
            free(minNode);
            return initnode(-1);
        } else {
            node = minNode->right;
            minNode->left->right = minNode->right;
            minNode->right->left = minNode->left;
        }
    }
    free(minNode);
    return consolidation(node);
}

int main() {
    FibNode* node = initnode(-1); 
    char command[20]; int key, value;
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            printLevelOrder(node);
            break;
        } else if (strcmp(command, "extract-min") == 0) {
            node = extract_min(node);
        } else if (strcmp(command, "insert") == 0) {
            scanf("%d", &key);
            node = insert(node, key);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%d", &key);
            node = decrease(node, key, key); 
            node = extract_min(node);
        } else if (strcmp(command, "decrease") == 0) {
            scanf("%d %d", &key, &value);
            node = decrease(node, key, value);
        }
    }
    free(node); 
    return 0;
}
