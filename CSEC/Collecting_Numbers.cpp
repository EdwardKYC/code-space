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
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin() , v.end());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].second < v[i-1].second) ans++;
    }
    cout << ans << '\n';
    return 0;
}