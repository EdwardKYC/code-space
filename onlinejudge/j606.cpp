#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k ,q ,r;
    cin >> k >> q >> r;
    string s1;
    cin >> s1;
    vector<string> s;
    for (int i = 0; i < q; i++) {
        string s2 = s1;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            s2[a - 1] = s1[i];
        }
        s1 = s2;
        s.push_back(s2);
    }
    for (int j = 0; j < r; j++) {
        for (int i = 0; i < q; i++) {
            cout << s[i][j];
        }
        cout << "\n";
    }
    return 0;
}