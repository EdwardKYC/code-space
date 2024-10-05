#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll k;
    for (ll j = 0; j < n; j++) {
        cin >> k;
        ll i = 1;            
        ll base = 9;         
        ll order = 1;      

        while (k > i * base) {
            k -= i * base;  
            i++;            
            base *= 10;     
            order *= 10;   
        }
        
        if (k != 0) {
            order += k/i;
            k %= i;
        }
        
        if (k == 0) {
            cout << (order-1)%10 << '\n';
        }
        else {
            string s = to_string(order);
            cout << s[k-1] << '\n';
        }
    }
    return 0;
}
