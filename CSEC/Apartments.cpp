#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
bool cmp(int x , int y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , m ,k;
    cin >> n >> m >> k;
    vector<ll> a(n) , b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    int ans = 0;
    for (int i = 0, j = 0; i < m && j < n;) {
        if (abs(a[j] - b[i]) <= k) {
            i++; j++;
            ans++;
        } 
        else if (a[j] < b[i]) {
            j++;
        } 
        else {
            i++;
        }
    }
    cout << ans << '\n';
    return 0;
}