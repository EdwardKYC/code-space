#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << '\n';
    return 0;
}