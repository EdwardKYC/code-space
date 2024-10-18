#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<ll, ll> prefix;
    ll current_sum = 0;
    ll ans = 0;
    prefix[0] = 1;
    for (ll i = 0; i < n; i++) {
        current_sum += v[i];
        current_sum %= n;
        if (current_sum < 0) current_sum += n;
        if (prefix.find(current_sum) != prefix.end()) {
            ans += prefix[current_sum];
        }
        prefix[current_sum]++;
    }
    cout << ans << endl;
    return 0;
}