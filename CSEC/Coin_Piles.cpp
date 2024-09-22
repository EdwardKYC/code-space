#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a , b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        a %= 3;
        b %= 3;
        if ((a == 2 && b == 1) || (a == 1 && b == 2) || (a == 0 && b == 0))
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }
    return 0;
}