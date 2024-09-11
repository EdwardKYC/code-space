#include <bits/stdc++.h>
using namespace std;
int main () {
    int t , n;
    cin >> t;
    for (int i = 0; i < t ;i++) {
        cin >> n; 
        vector<pair<string , int>> v(n);
        for (string &i : v.first)
            cin >> i;
        for (int j = 0; j < n; j++) {
            sort(v[j].first.begin() , v[j].first.end());
            char k = v[j].first[0];
            v[j].second = 1;
            for (int l = 1; l < v[j].first.size(); l++) {
                if (k != v[j].first[l]) {
                    k = v[j].first[l];
                    v[j].second++;
                }
            }
        }
    }
    return 0;
}