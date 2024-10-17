#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    map<ll,ll> mp;
    vll v(n);
    for (auto &i : v) cin >> i;
    ll ans = 0, d = 0, l = 0;
    for (int r = 0; r < n; r++) {
        if (mp[v[r]] == 0) d++;

        mp[v[r]]++;
        while (d > k) {
            mp[v[l]]--;
            if (mp[v[l]] == 0) d--;
            l++;
        }
        ans += r-l+1;
    }
    cout << ans;
    return 0;
}
