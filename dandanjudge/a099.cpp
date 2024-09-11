#include <bits/stdc++.h>
using namespace std;
int main () {


    cin.tie(0) -> sync_with_stdio(0);


    int n , ans;
    while (cin >> n) {
        ans ^= n;
    }
    cout << ans << '\n';
    return 0;
}