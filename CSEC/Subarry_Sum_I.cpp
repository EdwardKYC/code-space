#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , x;
    cin >> n >> x;   
    vll v(n);
    for (auto &i : v)cin >> i;
    int l = 0 , r = 0;
    int ans = 0;
    int sum = v[0];
    while (l < n && r < n) {
        if (sum > x) {
            sum -= v[l];
            l++;
        }
        else if (sum < x) {
            r++;
            sum += v[r];
        }
        else {
            ans++;
            sum -= v[l];
            l++;
        }
    }
    cout << ans;
    return 0;
}