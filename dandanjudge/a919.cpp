#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main () {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int t , mxT = 0; cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
        if (mxT < v[i]) mxT = v[i];
    }
    ll dp[mxT+1] = {0};
    dp[1] = dp[2] = 1;
    for (int n = 3; n <= mxT; n++) {
        for (int k = 1; k < n; k++) {
            ll sum = 0;
            for (int i = 1; i <= k; i++) {
                sum += power(i , (n+k-i));
                sum %= mod;
            }
            dp[n] += dp[k] * sum % mod;
            dp[n] %= mod;
        }
    }
    for (int i = 0; i < t; i++) {
        cout << dp[v[i]] << '\n';
    }
    return 0;
}