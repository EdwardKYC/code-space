#include <bits/stdc++.h>
using namespace std;
vector<string> order;
bool cmp (pair<int , string> a , pair<int , string> b) {
    
    if (a.first == b.first) {
        int oa , ob;
        for (int i = 0 ; i < order.size() ; i++) {
            if (order[i] == a.second)
                oa = i;
            if (order[i] == b.second)
                ob = i;
        }
        return ob > oa;
    }
    return a.first > b.first;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    map<string , int> shibodou;
    while (getline(cin, s)) {
        if (shibodou.find(s) != shibodou.end()) 
            shibodou[s]++;
        else if (shibodou.find(s) == shibodou.end()) {
            order.push_back(s);
            shibodou.insert({s, 1});
        }
    }
    vector<pair<int , string>> times(shibodou.size());
    for (int i = 0; i < times.size() ; i++) {
        times[i].first = shibodou[order[i]];
        times[i].second = order[i];
    }
    sort(times.begin() , times.end() , cmp);
    for (int i = 0; i < times.size() ; i++) {
        cout << times[i].second << '\n';
    }
    return 0;
}