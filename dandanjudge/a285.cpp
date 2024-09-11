#include <bits/stdc++.h>
using namespace std;
int main () {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n , k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (cin >> k) {
        if (k == 0) break;
        bool f = false;
        int mid , l = -1 , r = n-1;
        while (r - l > 1) {
            mid = (l+r)>>1;
            if (a[mid] == k) {
                f = true;
                break;
            }
            else if (a[mid] > k) {
                r = mid;
            }
            else l = mid;
        }
        if (!f) cout << 0 << '\n';
        else cout << mid+1 << '\n';
    }
    return 0;
}