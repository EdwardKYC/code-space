#include <bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n , k;
        cin >> n >> k;
        int a[n+1];
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i-1];
        }
        if (a[n] % k != 0) {S
            cout << 0 << '\n';
            continue;
        }
        bool f = true;
        int sum = a[n]/k , r = 1 , l = 0, ad = 0 , ans = 1;
        for (; r <= n; r++) {// 0 1 3 6 6 3 6 9
            if (a[r] - a[l] == sum) {
                l = r;
                if (a[r+1] - a[l] == 0) {
                    while (a[r+1] - a[l] <= 0 && r != n-1) {
                        ans++;
                        r++;
                        l++;
                    }
                }
            }
            else if (a[r] - a[l] > sum) {
                f = false;
                break;
            }
        }
        if(!f) {
            cout << 0 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}