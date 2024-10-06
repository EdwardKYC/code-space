#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vll v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin() , v.end());
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] > ans) {
            break;
        }
        ans += v[i];
    }
    cout << ans << '\n';
    return 0;
}