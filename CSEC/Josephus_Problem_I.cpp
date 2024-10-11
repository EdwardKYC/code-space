#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector< pair<int , bool> > v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {i+1 , true};
    }
    int idx = 0;
    int count = n;
    bool skip = false;
    while(count > 0) {
        if (idx > v.size() - 1) {
            idx = 0;
        }
        if (v[idx].second == true && !skip) {
            idx++;
            skip = true;
            continue;
        }
        if (v[idx].second == true && skip) {
            v[idx].second = false;
            cout << v[idx].first << " ";
            skip = false;
            count--;
        }
        else
            idx++;
    }
    return 0;
}
