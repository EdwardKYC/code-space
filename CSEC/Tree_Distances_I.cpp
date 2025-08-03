#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
vector<int> adj[maxn]; 
int in[maxn], out[maxn];
void dfs1(int u, int parent) {
    in[u] = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        in[u] = max(in[u], in[v] + 1);
    }
}
void dfs2(int u, int parent) {
    int max1 = -1, max2 = -1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (in[v] >= max1) {
            max2 = max1;
            max1 = in[v];
        } else if (in[v] > max2) {
            max2 = in[v];
        }
    }
    for (int v : adj[u]) {
        if (v == parent) continue;
        int use = (in[v] == max1 ? max2 : max1);
        out[v] = max(out[u] + 1, use + 2);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, -1);
    out[1] = 0;
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << max(in[i], out[i]) << " ";
    }
    cout << '\n';

    return 0;
}
