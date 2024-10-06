#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
bool cmp(pii x , pii y) {
    if (x.second == y.second) {
        return x.first > y.first;
    }
    return x.second < y.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &i : v) {
        int a , b;
        cin >> a >> b;
        i = {a , b};
    }
    int ans = 0 , time = 0;
    sort(v.begin() , v.end() , cmp);
    for (int i = 0; i < n; i++) {
        if (time <= v[i].first) {
            ans++;
            time = v[i].second;
        }
    }
    cout << ans << '\n';
    return 0;
}