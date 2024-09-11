#include <bits/stdc++.h>
using namespace std;
int main () {
    int q; 
    cin >> q;
    while (q--) {
        int n , k;
        double l = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            l += k;
        }
        double t = l/10;
        int tt = 0;
        while (t > 0) {
            t--;
            if (t >= 0)tt++;
        }
        cout << l-tt << '\n';
    }
    return 0;
}