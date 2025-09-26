#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));

    if (a[1] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[1][j] = 1;
        }
    } else {
        dp[1][a[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j]) % MOD + dp[i-1][j+1]) % MOD;
            }
        } else {
            int j = a[i];
            dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j]) % MOD + dp[i-1][j+1]) % MOD;
        }
    }

    ll ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
