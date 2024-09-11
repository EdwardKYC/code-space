#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<long long , long long>> v(n);
    vector<long long> dp(n+1 , 0);

    for (int i = 0 ; i < n ; i++) cin >> v[i].first;
    for (int i = 0 ; i < n ; i++) cin >> v[i].second;

    for (int i = 0; i < n; i++) {
        dp[i] = v[i].second;
        for (int j = 0; j < i ; j++) {
            if (v[i].first > v[j].first)
                dp[i] = max((v[i].second+dp[j]) , dp[i]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans , dp[i]);
    }
    cout << ans << '\n';
    return 0;
}