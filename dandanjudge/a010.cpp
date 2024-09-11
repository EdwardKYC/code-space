#include <bits/stdc++.h>//«eºó
using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector <string> v(n);
        vector <int> prefix_v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            prefix_v[i] = v[i].size() + (i == 0 ? 0 : prefix_v[i-1]);
        }
        int k;
        for (int i = 0; i < m; i++) {
            cin >> k;
            int j = 0;
            while (prefix_v[j] < k) 
                j++;
            if (j == 0)
                cout << v[j][k-1];
            else 
                cout << v[j][k-prefix_v[j-1]-1];
        }
        cout << '\n';
    }
    return 0;
}