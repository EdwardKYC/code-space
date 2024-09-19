#include <bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long n; 
    cin >> n;
    vector<int> v(n , {0});
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    for (int i = 0; i < n; i++) {
        if(v[i] != i) {
            cout << i << '\n';
            break;
        }
        else if (i == n-1)
            cout << n << '\n';
    }
}