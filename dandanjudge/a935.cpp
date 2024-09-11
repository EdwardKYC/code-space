#include<bits/stdc++.h>
using namespace std;
#define pii pair<int , int>
#define ll long long
int main () {
    ll mod = 1e9+7;
    int n;
    cin >> n;   
    int t[n+1];
    for (int i = 1 ; i <= n ; i++) {
        cin >> t[i];
    }
    vector<pii> a(n+1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll dp[n+1] = {0};
    for (int i = 1 ; i <= n ; i++) {
        for (int j = a[i].first ; j <= a[i].second ; j++) {
            if (dp[j] > t[i]) {
                dp[i] += (3*dp[j])%mod;
            }
            else {
                dp[i] += dp[j]%mod;
            }
            dp[i] %= mod; 
        }
        dp[i] += t[i];
        dp[i] %= mod;
    }
    cout << dp[n] << '\n';
    return 0;
}