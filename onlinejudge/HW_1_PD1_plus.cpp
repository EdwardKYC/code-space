#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")

#include <iostream>
#include <array>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXN 200005

array<int, 26> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

ll modInverse(ll a) {
    ll res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

inline int charToPrime(char c) {
    return p[c - 'a'];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();

    array<ll, MAXN> hash1{}, hash2{}, inv1{}, inv2{};
    hash1[0] = hash2[0] = inv1[0] = inv2[0] = 1;

    for (int i = 1; i <= n1; i++) hash1[i] = (hash1[i - 1] * charToPrime(s1[i - 1])) % mod;
    for (int i = 1; i <= n2; i++) hash2[i] = (hash2[i - 1] * charToPrime(s2[i - 1])) % mod;
    for (int i = 1; i <= n1; i++) inv1[i] = modInverse(hash1[i]);
    for (int i = 1; i <= n2; i++) inv2[i] = modInverse(hash2[i]);

    int q;
    cin >> q;
    while (q--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        ll ans1 = (hash1[a2] * inv1[a1 - 1]) % mod;
        ll ans2 = (hash2[b2] * inv2[b1 - 1]) % mod;
        cout << (ans1 == ans2 ? "YES\n" : "NO\n");
    }
    return 0;
}
