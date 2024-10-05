#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll sum = 0, sum1 = 0, sum2 = 0 , ans = LLONG_MAX;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
        sum += i;
    }
    for (int m = 0; m < (1 << n); m++) {
        sum1 = 0;
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                sum1 += a[i];
            }
        }
        sum2 = sum - sum1;
        sum1 = abs(sum1 - sum2);
        ans = min(sum1 , ans);
    }
    cout << ans << '\n';
    return 0;
}
