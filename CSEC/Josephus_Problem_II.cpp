#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()
const int mod = 1e9 + 7;
#define MAXN 200005  

int n, k;
int tree[4*MAXN];  

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = 1;
        return;
    }
    int mid = (l + r)/2;
    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

void update(int node, int l, int r, int idx) {
    if (l == r) {
        tree[node] = 0;
        return;
    }
    int mid = (l + r)/2;
    if (idx <= mid) update(2 * node, l, mid, idx);
    else update(2*node + 1, mid + 1, r, idx);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r)/2;
    if (tree[2*node] >= k) return query(2*node, l, mid, k);
    else return query(2*node + 1, mid + 1, r, k - tree[2*node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    build(1, 1, n);

    int curr = 0; 

    for (int i = n; i >= 1; i--) {
        curr = (curr + k) % i;
        int pos = query(1, 1, n, curr + 1);
        cout << pos << " ";
        update(1, 1, n, pos); 
    }

    cout << '\n';
    return 0;
}
