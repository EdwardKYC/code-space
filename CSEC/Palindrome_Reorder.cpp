#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    vector<int> v(26, 0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v[int(s[i]-65)]++;
    }
    bool one_odd = false;
    bool no_solution = false;
    
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 == 1 && !one_odd) {
            one_odd = true;
        }
        else if (v[i] % 2 == 1 && one_odd) {
            cout << "NO SOLUTION" << '\n';
            no_solution = true;
            break;
        }
    }
    
    if (one_odd && !no_solution) {
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 != 0) {
                continue;         
            }
            for (int j = 0; j < v[i]/2; j++)
                cout << char(i+65);
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 != 0) {
                for (int j = 0; j < v[i]; j++)
                    cout << char(i+65);
                v[i] = 0;
                break;  
            }
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < v[i]/2; j++)
                cout << char(i+65);
        }
    }
    else if (!one_odd && !no_solution) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < v[i]/2; j++)
                cout << char(i+65);
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < v[i]/2; j++)
                cout << char(i+65);
        }
    }
    return 0;
}