#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define mod 1000000007  

vector<int> p = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
};
int charToPrime(char c) {
    return p[c - 'a'];
}
ll moduse(ll a) {
    ll res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    vector<ll> hash1(n1 + 1, 1), hash2(n2 + 1, 1);
    for (int i = 1; i <= n1; i++)  hash1[i] = (hash1[i - 1] * charToPrime(s1[i - 1])) % mod;
    for (int i = 1; i <= n2; i++)  hash2[i] = (hash2[i - 1] * charToPrime(s2[i - 1])) % mod;

    int q;
    cin >> q;
    while (q--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        ll ans1 = (hash1[a2] * moduse(hash1[a1 - 1])) % mod;
        ll ans2 = (hash2[b2] * moduse(hash2[b1 - 1])) % mod;
        if (ans1 == ans2)  cout << "YES\n";
        else  cout << "NO\n";
    }
    return 0;
}
