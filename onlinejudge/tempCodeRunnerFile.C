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
        del->data = -1;
        free(last);
        return;
    }
    del->data = last->data;
    if (last->farther != NULL) {
        if (last->farther->left == last) last->farther->left = NULL;
        else if (last->farther->right == last) last->farther->right = NULL;
    }
    free(last);
    downfind(del);
}