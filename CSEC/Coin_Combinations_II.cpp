#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, 0); 
    vector<ll> c(n);
    for (auto &i : c) {
        cin >> i;
    }

    dp[0] = 1; 

    for (int j = 0; j < n; j++) { 
        for (int i = c[j]; i <= x; i++) { 
            dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }

    cout << dp[x]; 
    return 0;
}
