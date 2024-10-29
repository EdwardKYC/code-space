#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()


ll power(ll n, ll x, ll mod) { //n^x
    ll result = 1;
    n %= mod;
    while (x > 0) {
        if (x % 2 == 1) result = (result * n) % mod;
        n = (n * n) % mod;
        x /= 2;
    }
    return result;
}
bool fermat(int x, int iterations = 5) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2, x - 2); 

    for (int i = 0; i < iterations; i++) {
        int a = dist(gen);
        if (power(a, x - 1, x) != 1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x;
    while (cin >> x) {
        bool f = fermat(x); 
        if (f) cout << "質數" << '\n';
        else cout << "非質數" << '\n';
    }
    return 0;
}