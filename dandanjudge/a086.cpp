#include <bits/stdc++.h>
using namespace std; 
bool cmp(pair <int , int> a ,pair <int , int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    else
        return a.second < b.second;
}
int main () {
    string s;
    while (getline(cin , s)) {
        vector <pair <int , int> > v;//½s¸¹ »ù­È
        int k = 1 , d;
        stringstream ss(s);
        while (ss >> d) {
            pair <int , int> p = make_pair(k , d);
            v.push_back(p);
            k++;
        }
        sort (v.begin() , v.end() , cmp);
        for (int i = 0 ; i < v.size() ;i++) {
            if (i == v.size()-1)
                cout << v[i].first << "\n" ;
            else
                cout << v[i].first << " " ;
        }
    }
    return 0;
}