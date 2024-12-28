#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
vector< vector<ll> > dp(1001 , vector<ll>(1001 , 0));
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '*') dp[i][j] = -1;
        }
    }
    if (dp[1][1] == -1 || dp[n][n] == -1) {
        cout << 0;
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == -1) continue;
            if (dp[i-1][j] == -1) dp[i][j]++;
            if (dp[i][j-1] == -1) dp[i][j]++;
            dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    
    cout << dp[n][n];
    return 0;
}