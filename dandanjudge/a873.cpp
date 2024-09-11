#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n , ai;
    cin >> n;
    vector<int> a , b , ans(n);
    bool c[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> ai;
        if (ai % 2 == 0) {
            b.push_back(ai);
            c[i] = false;
        }
        else {
            a.push_back(ai);
            c[i] = true;
        }
    }
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    int ad = 0, bd = 0;
    for (int i = 0 ; i < n ; i++) {
        if (c[i] == true) {
            ans[i] = a[ad];
            ad++;
        }
        else {
            ans[i] = b[bd];
            bd++;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << " " ;
    }
    cout << '\n';
    return 0;
}