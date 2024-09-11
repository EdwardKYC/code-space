#include<bits/stdc++.h>
using namespace std;
int main () {
    int n , m , a , b;
    cin >> n >> m;
    int out[n] = {0};
    vector<int> enter[m];
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        enter[b].push_back(a);
        out[a]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        ans.push_back(k);
        for (int i = 0 ; i < enter[k].size() ; i++) {
            out[enter[k][i]]--;
            if (out[enter[k][i]] == 0)
                q.push(enter[k][i]);
        }
    }
    for (int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}