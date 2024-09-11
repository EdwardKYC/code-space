#include<bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n , k;
    cin >> n >> k;
    vector<string> v(n);
    string str , fs;
    cin >> str;
    int idx = 0 , m;
    while (str.find("...") != -1) {
        m = str.find("..." , 0);
        fs = str.substr(0 , m);
        v[idx] = fs;
        str = str.substr(m+3 , str.size());
        idx++;
    }
    v[idx] = str;
    string sss = v[0];
    long long a , ans = 0;
    for (int i = 0; i < n ; i++) {
        if (i != 0) {
            sss = sss+v[i];
        }
        a = stoll(sss);
        if (a % k == 0)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}