#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s = ":poop:";
    string str , fs;
    int ans = 0;
    while (getline(cin , str)) {
        if (cin.eof()) {
            break;
        }
        int start = 0 , idx = 0;
        while (str.find(' ') != -1) {
            idx = str.find(' ' , 0);
            fs = str.substr(0 , idx);
            if (fs == s)
                ans++;
            str = str.substr(idx+1 , str.size());
        }
        if (str == s)
                ans++;
        
    }
    cout << ans << '\n';
    return 0;
}