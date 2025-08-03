#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
ll exp(ll a, ll b) {
    if (b == 0) return 1;
    if (a == 0) return 0;
    ll res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll a, b;
    while (n--) {
        cin >> a >> b;
        cout << exp(a, b) << '\n';
    }
    return 0;
}