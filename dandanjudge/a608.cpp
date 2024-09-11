#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
void f (vector<ll> &allK , int n , int ks , ll k) {
    if (n <= ks) {
        ll kd;
        if (n == 1) kd = k-n;
        else kd = k-n*10;
        allK.push_back(k);
        allK.push_back(kd);
        f(allK , n+1 , ks ,kd);
        f(allK , n+1 , ks ,k);
    }
    else return;
}
int main () {
    ll t , n; cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
            cout << 0 << endl;
            continue;
        }
        ll k = 11 , ks = 2;
        while (k/n != 1) {
            k = k*10 + 1;
            ks++;
        }
        vector<ll> allK;
        f(allK , 1 , ks , k);
        for (int i = 0 ; i < allK.size() ; i++) {
            if (allK[i]%n == 0) ans++;
        }
        cout << ans%mod << '\n';
    }
    return 0;
}