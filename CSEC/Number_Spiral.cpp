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
        if (a == b)
            cout << a*a - a + 1 << '\n';
        else if (a > b && a % 2 == 0) 
            cout << a*a - b + 1 << '\n';
        else if (a > b && a % 2 != 0) 
            cout << a*a - 2*a + b + 1 << '\n';
        else if (a < b && b % 2 == 0) 
            cout << b*b - 2*b + a + 1 << '\n';
        else if (a < b && b % 2 != 0) 
            cout << b*b - a + 1 << '\n';
    }
    return 0;
}