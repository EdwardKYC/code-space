#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int max_n = 1e6;
    vector<ll> full(max_n+1 , 0) , half(max_n+1 , 0);
    full[1] = half[1] = 1;

    for (int i = 2; i <= max_n; i++) {
        full[i] = (2 * full[i-1] + half[i-1]) % mod;
        half[i] = (4 * half[i-1] + full[i-1]) % mod;
    }

    int t , n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (full[n] + half[n]) % mod <<'\n';
    }
    return 0;
}