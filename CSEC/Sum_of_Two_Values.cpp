#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int> 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , x;
    cin >> n >> x;
    vector<pii> v(n);
    for (int k = 0; k < n; k++) {
        cin >> v[k].first;
        v[k].second = k;
    }
    sort(v.begin() , v.end());
    int i = 0 , j = n-1 ;
    bool f = false;
    while (i < j) {
        if (v[i].first + v[j].first > x) j--;
        else if (v[i].first + v[j].first < x) i++;
        else {
            cout << v[i].second+1 << " " << v[j].second+1 << '\n';
            f = true;
            break;
        }
    }
    if (!f) {
        cout << "IMPOSSIBLE" <<'\n';
    }
    return 0;
}