#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cout << (i*i * (i*i-1))/2 - 4*(i-1)*(i-2) << '\n';
    }
    return 0;
}