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
    multiset<int> v;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        auto it = v.upper_bound(k);
        if (v.empty() || it == v.end()) {
            v.insert(k);
        }
        else {
            v.erase(it);
            v.insert(k);
        }
    }
    cout << v.size() << '\n';
    return 0;
}