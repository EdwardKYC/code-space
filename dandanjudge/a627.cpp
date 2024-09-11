#include <bits/stdc++.h>
using namespace std;
int main() {
    int t , n; cin >> t;
    while (t--) {
        cin >> n;
        int a[n] , idx = 0;
        vector <int> v(1);
        v[0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i-1]) {
                v[idx]++;
            }
            else {
                idx++;
                v.push_back(0);
                v[idx]++;
            }
        }
        int ans = 0;
        for (int i = 0 ; i < v.size(); i++) {
            ans = max(ans , v[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}