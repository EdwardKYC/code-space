#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k, n;
    ll sumb = 0, sums = 0;
    cin >> n >> k;
    vll v(n);
    for (auto &i : v)cin >> i;
    multiset<ll> bigst , smast;
    smast.insert(v[0]);
    sums += v[0];
    for (int i = 1; i < k; i++) {
        int s = *smast.rbegin();
        int b = *bigst.begin();
        if (v[i] >= s) {
            if (smast.size() > bigst.size()) {
                bigst.insert(v[i]);
                sumb += v[i];
            }
            else {
                if (v[i] >= b){
                    smast.insert(b);
                    bigst.erase(b);
                    bigst.insert(v[i]);
                    sums += b;
                    sumb += v[i]-b;
                }
                else {
                    smast.insert(v[i]);
                    sums += v[i];
                }
            }
        }
        else {
            if (smast.size() == bigst.size()) {
                smast.insert(v[i]);
                sums += v[i];
            }
            else {
                smast.erase(s);
                bigst.insert(s);
                smast.insert(v[i]);
                sums += v[i]-s;
                sumb += s;
            }
        }
    }
    int ans = 0;
    ans += (smast.size() * (*smast.rbegin()) - sums);
    ans += abs(bigst.size() * (*smast.rbegin()) - sumb);
    cout << ans << " ";
    for (int i = k; i < n; i++) {
        int s = *smast.rbegin();
        int b = *bigst.begin();

    }
    return 0;
}