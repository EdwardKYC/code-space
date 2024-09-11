#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string , pair<string , int > >  a , pair<string , pair<string , int > > b) {
    return a.second.second > b.second.second;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    map<char, int> m;
    for (char c = 'a'; c <= 'z'; ++c) {
        m[c] = int(c - 'a' + 1);
    }
    while (cin >> n) {
        if (n == 0)
            break;
        vector <pair<string , pair<string , int > > > v(n);
        for (int i = 0; i < n;i++) {
            cin >> v[i].first;
            v[i].second.first = v[i].first;
            v[i].second.second = 0;
            for (int j = 0; j < v[i].first.size() ; j++) {
                v[i].first[j] = tolower(v[i].first[j]);

                if (m.find(v[i].first[j]) == m.end())
                    v[i].second.second--;
                else
                    v[i].second.second += m[v[i].first[j]];
            }
        }
        sort(v.begin() , v.end() ,cmp);
        if (v[0].second.second <= 0)
            cout << "Princess is still single. :(" <<'\n';
        else 
            cout << v[0].second.first << '\n';
    }
    return 0;
}   