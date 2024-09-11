#include <bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    long long ans[t];
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        ans[i] = 0;
        long long k = 5;
        while (k <= n) {
            ans[i] += n / k;
            k *= 5;
        }
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}