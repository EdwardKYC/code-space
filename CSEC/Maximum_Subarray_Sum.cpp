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
    for (auto &i : v) cin >> i;
    ll sum = v[0];
    ll max_sum = v[0];
    for (int i = 1; i < n; i++) {
        sum = max(v[i] , v[i] + sum);
        max_sum = max(max_sum , sum);
    }
    cout << max_sum << '\n';
    return 0;
}