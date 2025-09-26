#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t , n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        dp[1][0] = 1; 
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0]*2;
        }
    }
    return 0;
}