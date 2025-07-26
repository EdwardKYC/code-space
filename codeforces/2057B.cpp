#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, a;
        cin >> n >> k;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a;
            mp[a]++;
        }

        if (k >= n) {
            cout << 1 << '\n';
            continue;
        }
        int sum = mp.size();
        vll v;
        for (auto &i : mp) {
            v.push_back(i.second);
        }
        sort(ALL(v));
        for (int i = 0; i < v.size(); i++) {
            if (k >= v[i]) {
                sum--;
                k -= v[i];
            }
            else break;
        }
        
        cout << sum << '\n';
    }

    return 0;
}
