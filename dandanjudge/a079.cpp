#include<bits/stdc++.h>
using namespace std;
int main () {
    int n , M;
    while (cin >> n >> M) {
        int t;
        vector<int> v(n);
        priority_queue<int, vector<int>, greater<int>> m; 
        for (int i = 0 ; i < n ; i++) {
            cin >> v[i];
        }
        for (int i = 0 ; i < M ; i++) {
            m.push(v[i]);
        }
        for (int i = M ; i < n ; i++) {
            t = m.top() + v[i];
            m.pop();
            m.push(t);
        }
        int ans;
        while (!m.empty()) {
          ans = m.top();
            m.pop();
        }
        cout << ans << '\n';

    }
    return 0;
}