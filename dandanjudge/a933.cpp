#include <bits/stdc++.h>
using namespace std ;
int main () {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    string s , ms;
    int n , ans = 0 , idx = 0 , k = 0;
    bool find = false;
    cin >> s >> n;
    while (cin >> ms) {
        for (int i = 0; i < ms.length(); i++) {
            if (s[idx] == ms[i]) {
                idx++;
                ans += i+1+k;
            }
            if (idx == s.length()) {
                find = true;
                break;
            }
        }
        if (find) break;
        else if (ans > n) {
            find = false;
            break;
        }
        k += ms.length();
    }
    if (find) {
        cout << "咕嚕靈波（○´∀｀）ノ♡" << endl;
    } else {
        cout << "error" << endl;
    }
    return 0;
}
