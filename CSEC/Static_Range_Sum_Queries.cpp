#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n+1 , 0);
    v[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] += v[i-1];

    }
    while(q--) {
        int a , b;
        cin >> a >> b;
        cout << v[b] - v[a-1] << '\n';
    }
    return 0;
}