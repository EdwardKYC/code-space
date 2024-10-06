#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; 
    cin >> n;
    vll v(n);
    double sum = 0;
    for (auto &i : v) cin >> i;
    ll ans = 0;
    sort(v.begin() , v.end());
    ll mid ;
    if (n % 2 == 0) {
        mid = (v[n/2 - 1] + v[n/2]) / 2;
    }
    if (n % 2 != 0) {
        mid = v[n/2];
    }
    for (int i = 0; i < n; i++) {
        ans += abs(mid - v[i]);
    }
    cout << ans << '\n';
    return 0;
}