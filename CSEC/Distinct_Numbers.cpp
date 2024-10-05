#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin() , v.end());
    int ans = 1;
    for (int i = 1 ; i < n; i++) {
        if (v[i] != v[i-1]) {
            ans++;
        }
    } 
    cout << ans << '\n';
    return 0;
}
