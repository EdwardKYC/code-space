#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
void f(int n) {
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
    }
    else if (n == 1) {
        cout << 1 << '\n';
    } 
    else {
        for (int i = 2; i <= n; i += 2)
               cout << i << " ";
        for (int i = 1; i <= n; i += 2)
            cout << i << " ";
    }
    return ;
}
int main () {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n;
    cin >> n;
    f(n);
    return 0;
}