#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}