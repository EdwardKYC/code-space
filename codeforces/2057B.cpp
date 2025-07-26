#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n , k , a;
        map<int , int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a;
            mp[a]++;
        }
        int sum = 0;
        vll v;
        for (auto &i : mp) {
            v.push_back(i.second);
            sum += i.second;
        }

        vector<int> dp(k + 1, 0);

        for (int value : v) {
            for (int j = k; j >= value; j--) {
                dp[j] = max(value , dp[j-value] + value);
            }
        }
        cout << sum - dp[k] << '\n';
    }
    return 0;
}