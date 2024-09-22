#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n;
    cin >> n;
    int ans = 0;
    while (n >= 5) {
        ans += n/5;
        n /= 5;
    }
    cout << ans << '\n';
    return 0;
}