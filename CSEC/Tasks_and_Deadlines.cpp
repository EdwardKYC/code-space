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
    vector<pii> v(n);
    for (auto &i : v) cin >> i.first >> i.second;
    sort(ALL(v));
    ll time = 0 , reward = 0;
    for (ll i = 0; i < n; i++) {
        time += v[i].first;
        reward += (v[i].second - time);
    }
    cout << reward;
    return 0;
}