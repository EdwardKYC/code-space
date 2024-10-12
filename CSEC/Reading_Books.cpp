#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum_all = 0, max_time = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum_all += v[i];   
        max_time = max(max_time, v[i]); 
    }
    ll result = max(sum_all, 2 * max_time);
    cout << result << '\n';

    return 0;
}