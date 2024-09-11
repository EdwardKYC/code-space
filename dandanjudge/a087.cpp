#include<bits/stdc++.h>
using namespace std;
int recursion(int k , int n) {
    int ans = 0;
    if (n <= 0)
        return 0;
    else if (n == 1) 
        return 1;
    else {
        
        if (k >= n) {
            for (int i = 1; i <= k ; i++) ans += recursion(k , n-i);
            ans++;
        }
        
        else {
            for (int i = 1; i <= k ; i++) ans += recursion(k , n-i);
        }
    }
    return ans;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k , n;
    while (cin >> k >> n) {
        if (k == 0 && n == 0) {
            break;
        }
        else
            cout << recursion(k , n) << '\n';
    }
    return 0;
}