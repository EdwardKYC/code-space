#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        ll a = 0, b = 0, c = 0;
        for(ll i = 30; i >= 0; --i) {
            bool x = l & (1LL << i), y = r & (1LL << i);
            if(x == y) {
                if(x) a |= (1LL << i);
                if(y) b |= (1LL << i);
            }else {
                a |= (1LL << i);
                b |= (1LL << i) - 1;
                break;
            }
        }
        for(ll i = l; i <= r; ++i) {
            if(i != a && i != b) {
                c = i;
                break;
            }
        }
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}