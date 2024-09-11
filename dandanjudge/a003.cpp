#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    while (cin >> s) {
        for (int i = 0; i < 6; i++) {
            cout << abs(int(s[i+1])-int(s[i]));
        }
        cout <<'\n';
    }
    return 0;
}