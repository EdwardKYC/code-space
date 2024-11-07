#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct leftist node;
struct leftist
{
    int data;
    int shortest;
    bool deleted;
    node *left;
    node *right;
    node *parent;
};
node* father(node *x){
    if (x->parent == NULL)
        return x;
    return father(x->parent);
}
bool samestack(node *x , node *y){
    return father(x) == father(y);
}
node* change(node *a, node *b)
{
    return b;
}
void merge(node *Ta , node *Tb) {
    if (Ta == NULL || Tb == NULL)    return;
    if (Ta->data > Tb->data) {
        node *tmepa = Ta, *tmepb = Tb;
        Ta = change(tmepa, tmepb);
        Tb = change(tmepb, tmepa);
    }
    if (Ta->right != NULL) {
        merge(Ta->right , Tb);
        Ta->right->parent = NULL;
        Ta->right = Tb;
        Tb->parent = Ta;
        return;
    }
    Ta->right = Tb;
    Tb->parent = Ta;
    return;
}
int count(node *n) {
    if (n == NULL) {
        return 0;
    }
    int left_count = count(n->left);
    int right_count = count(n->right);
    n->shortest = 1 + (left_count < right_count ? left_count : right_count);
    return n->shortest;
}

void shortestcheck(node *n)
{
    if (n == NULL || n->left == NULL || n->right == NULL)
        return;

    if (n->left->shortest < n->right->shortest)
    {
        node *temp = n->right;
        n->right = n->left;
        n->left = temp;
    }
    shortestcheck(n->left);
    shortestcheck(n->right);
}
void delete(node *n) {
    n->deleted = true;
    merge(n->left , n->right);
    shortestcheck(father(n->left));
}
int main () {
    int n , m;
    scanf("%d %d", &n ,&m);
    node *s[n];
    for (int i = 0; i < n; i++) {
        s[i] = (node *)malloc(sizeof(node));
        s[i]->left = NULL; 
        s[i]->right = NULL; 
        s[i]->parent = NULL; 
        s[i]->shortest = 1; 
        s[i]->deleted = false;
        scanf("%d", &s[i]->data);
    }
    int situation , x , y;
    for (int i = 0; i < m; i++) {
        scanf("%d" , &situation);
        if (situation == 1){
            scanf("%d %d" , &x , &y);
            if (!s[x]->deleted && !s[y]->deleted)
                break;
            if (samestack(s[x] , s[y])) continue;;
            merge(father(s[x]) , father(s[y]));
            shortestcheck(father(s[x]));    
        }
        else {
            scanf("%d", &x);
            if(s[x]->deleted) printf("-1\n");
            else {
                delete(father(s[x]));
                printf("%d\n" , father(s[x])->data);
            }
            
        }
    }
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    return 0;
}