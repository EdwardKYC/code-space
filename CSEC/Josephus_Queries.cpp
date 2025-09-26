#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;

ll solve(ll n, ll k) {
    if (n == 1) return 1;
    ll hf = (n + 1) / 2;
    if (k <= hf) {
        ll ans = 2 * k;
        return (ans > n ? ans - n : ans);
    }
    ll rest = solve(n >> 1, k - hf);
    if (n & 1) return 2 * rest + 1;
    else return 2 * rest - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}
// 3 5 7 -> 1 2 3
// 1 3 5 7 -> 1 2 3 4