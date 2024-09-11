#include<bits/stdc++.h>
using namespace std;
int main () {
    int t , p , q , k;
    cin >> t; 
    while (t--) {
        cin >> p >> q;
        int a[100001] = {0} , b[100001] = {0};
        for (int i = 0 ; i < p ; i++) {
            cin >> k;
            a[k]++;
        }
        for (int i = 0 ; i < q ; i++) {
            cin >> k;
            b[k]++;
        }   
        int an[100001] = {0} , bn[100001] = {0} , bw = 0, aw = 0;
        for (int i = 1 ; i <= 100000 ; i++) {
            if (a[i] > 1 && b[i] == 0) {
                bn[i]++;
                bw++;
            }
            if (b[i] > 1 && a[i] == 0) {
                an[i]++;
                aw++;
            }
        }    
        if (aw == 0 || bw == 0) cout << 0 << '\n';
        else {
            int ans = min(aw , bw);
            cout << ans << '\n';
            for (int i = 1; i <= 100000; i++) {
                if (bn[i] != 0) cout << i << " ";
            }
            cout << '\n';
            for (int i = 1; i <= 100000; i++) {
                if (an[i] != 0) cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
