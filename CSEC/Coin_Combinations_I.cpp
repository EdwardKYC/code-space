#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9+7;
bool cmp(int a , int b) {
    return a < b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n , x;
    cin >> n >> x;
    vector<ll> dp(x + 1, 0);
    vector<ll> c(n);
    for (auto &i : c) cin >> i;
    sort(ALL(c) , cmp);
    for (int i = 0; i < x+1; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] == i) {
                dp[i] += 1;
                dp[i] %= mod;
                break;
            }else if (c[j] < i) {
                if (dp[i - c[j]] == 0) continue;
                dp[i] += dp[i - c[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x];
    return 0;
}