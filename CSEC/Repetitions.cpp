#include <bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    int ans = 1 , k = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            k++;
            ans = max(ans , k);
        }
        else {
            k = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}