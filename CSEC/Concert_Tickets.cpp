#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
bool cmp(int x , int y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , m , price;
    cin >> n >> m;
    vector<ll> t(m);
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        cin >> price;
        h.insert(price);
    }
    for(auto &i : t) cin >> i;
    for(auto &i : t) {
        auto it = h.upper_bound(i);
        if (it == h.begin()) {
            cout << -1 << '\n';
        }
        else {
            it--;
            cout << *it << '\n';
            h.erase(it);
        }
    }
    return 0;
}