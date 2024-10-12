
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , t;
    cin >> n >> t;
    vll v(n);
    for (auto &i : v)cin >> i;
    sort(ALL(v));
    ll l = 0 , r = v[0]*t + 1 , ans;
    while (r > l) {
        ll mid = (r+l)/2 , p = 0;
        for (int i = 0; i < n; i++) {
            p += mid/v[i];
        }
        if (p >= t) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}