#include <bits/stdc++.h>
using namespace std;    
#define ll long long  
const int mod = 1e9 + 7 ;  
void multiply(ll a[3][3], ll b[3][3], ll (*r)[3][3]) {
    ll res[3][3] = {{0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    memcpy(r, res, sizeof(res));
}
ll f(ll next[3][3], ll n) {
    ll base[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    while (n > 0) {
        if (n & 1) {
            ll (*b)[3][3] = &next;
            multiply(next , base , b);
        }
        n >>= 1;
        ll (*b)[3][3] = &base;
        multiply(next, next, b);
    }
    return base[0][0];
    
}
int main () {
    ll next[3][3] = {{1 , 1 , 1} , {1 , 0 , 0} , {0 , 1 , 0}} ; 
    ll ans , n ;
    while(cin >> n) {
    	if (n == 1) {
    		cout << 1 << '\n' ;
		}
		else if (n == 2) {
    		cout << 2 << '\n' ;
		}
		else if (n == 3) {
    		cout << 4 << '\n' ;
		}
		else {
			ans = f(next , n-2) ; 
   	        cout << ans << '\n' ;
		}
    }
    return 0 ;
}
