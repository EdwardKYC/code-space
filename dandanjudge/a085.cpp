#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string , pair<int , int>> a , pair<string , pair<int , int>> b) {
    return (a.second.first == b.second.first ? a.first < b.first : a.second.first < b.second.first);
}
int main () {
    int n;
    cin >> n;
    vector <string> temp_v(n);
    vector < pair< string , pair<int , int> > > v(n , {" ", {0 , 0}});
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        temp_v[i] = v[i].first;
        v[i].second.second = i;
        sort (v[i].first.begin() , v[i].first.end());
    }
    for (int i = 0; i < n; i++) {
        char k = v[i].first[0];
        v[i].second.first = 1;
        for (int j = 0; j < v[i].first.size(); j++) {
            if (k != v[i].first[j]) {
                k = v[i].first[j];
                v[i].second.first++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        v[i].first = temp_v[i];
    }
    sort (v.begin() , v.end() , cmp);
    for (int i = 0; i < n; i++) {
        cout << v[i].first <<'\n';
    }
    return 0;   
}