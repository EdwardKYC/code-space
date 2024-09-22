#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    int ans = 1;
    for (ll i = 0; i < n; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}