#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int tree[4*maxn];
vector<int> ht;
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = ht[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = max(tree[2*node], tree[2*node + 1]);
}
int query(int node, int l, int r, int x) {
    if (tree[node] < x) return 0;
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    if (tree[2*node] >= x) return query(2*node, l, mid, x);
    else return query(2*node + 1, mid + 1, r, x);
}
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] -= val;
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid) update(2*node, l, mid, idx, val);
    else update(2*node + 1, mid + 1, r, idx, val);
    tree[node] = max(tree[2*node], tree[2*node + 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;
    ht.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> ht[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int idx = query(1, 1, n, x);
        if (idx == 0) cout << "0";
        else {
            cout << idx;
            update(1, 1, n, idx, x);
        }
        cout << " ";
    }   
    return 0;
}   