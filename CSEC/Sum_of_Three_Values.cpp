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
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }    
    sort(ALL(v));
    bool find = false;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            int l = j+1 , r = n-1;
            while (r >= l) {
                int mid = (r+l)/2 , sum = v[i].first+v[j].first+v[mid].first;
                if (sum > x) r = mid - 1;
                else if (sum < x) l = mid + 1;
                else {
                    find = true;
                    cout << v[i].second << " " << v[j].second << " " << v[mid].second;
                    break;
                }
            }
            if (find) break;
        }
        if (find) break;
    }
    if (!find) cout << "IMPOSSIBLE";
    return 0;
}
