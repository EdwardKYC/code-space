#include <bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n ;
    while (cin >> n) {
        map<int , int> m;
        for (int i = 0; i < n ; i++) {
            int k , u;
            cin >> k >> u;
            if(m.find(k) == m.end())
                m.insert({k , u});
            else
                m[k] += u;
        }
        int q;
        cin >> q;
        auto it = m.find(q);
        cout << it->second << '\n';
    }
    return 0;
}