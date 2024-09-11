#include <bits/stdc++.h>
using namespace std;
#define pii pair<int , int>
int f(vector<pii> v , int mid) {
    int t;
    priority_queue <int , vector<int> , greater<int>> m;
    for (int i = 0 ; i < mid ; i++) {
        m.push(v[i].first);
    }
    for (int i = mid ; i < v.size() ; i++) {
        t = m.top() + v[i].first;
        if (t > v[i].second) return 0;
        else {
            m.pop();
            m.push(t);
        }
    }
    return 1;
}
int main () {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n == 0) break; 
        int d = 0 , b;
        vector<pii> v(n);
		for (int i = 0 ; i < n ; i++) cin >> v[i].first;
        for (int i = 0 ; i < n ; i++) cin >> v[i].second;
        for (int i = 0 ; i < n ;  i++) {
            if (v[i].first > v[i].second) {
                cout << -1 << '\n';
                d = 1;
                break;
            }
        }
        if (d & 1) continue;

        

        int r = n+1 , l = 0 , mid , ans;

        while (r - l > 1) {
            mid = (r+l)>>1;
            b = f(v , mid);
            if (b & 1) {
                if (f(v , mid-1) == 0) {
                    ans = mid;
                    break;
                }
                else r = mid;
            }
            else l = mid;
        }
        cout << ans-1 << '\n';
    }
    return 0;
}