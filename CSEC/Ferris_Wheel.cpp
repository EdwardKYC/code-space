#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n , x , ans = 0;
    cin >> n >> x;
    vector<ll> p(n);
    for(auto &i : p) cin >> i;
    sort(p.begin() , p.end());
    int i = 0, j = n - 1;
    
    // 雙指針策略
    while (i <= j) {
        if (p[i] + p[j] <= x) {
            i++;
        }
        j--;
        ans++;
    }
    
    cout << ans << '\n';
    return 0;
}