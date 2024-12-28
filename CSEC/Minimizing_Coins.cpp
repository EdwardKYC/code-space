#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

bool cmp(int a , int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , x;
    cin >> n >> x;
    vector<int> dp(x + 1, -1);
    vector<int> c(n);
    for (auto &i : c) cin >> i;
    sort(ALL(c) , cmp);
    for (int i = 0; i < x+1; i++) {
        int temp = INT32_MAX;
        for (int j = 0; j < n; j++) {
            if (c[j] == i) {
                dp[i] = 1;
                break;
            }else if (c[j] < i) {
                if (dp[i - c[j]] == -1) continue;
                dp[i] = min(temp , 1 + dp[i - c[j]]);
                temp = dp[i];
            }
        }
    }
    cout << dp[x];
    return 0;
}