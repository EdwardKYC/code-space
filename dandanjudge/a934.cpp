#include<bits/stdc++.h>
using namespace std;
int main () {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    long long n , ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n-1 ; i++) {
        for (int j = 0 ; j < n-1-i ; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j] , a[j+1]);
                ans += a[j]+a[j+1];
            }  
        }
    }
    cout << ans << '\n';
    return 0;
}
