#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n , m , r , l , mid , k , k1;
    ll max = 0;
    while (cin >> n >> m) {
        m = m*2;
        ll a[n];
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
            if (a[i] > max) max = a[i];//找出最大的木棒粗度
        } 
        r = max; 
        l = 0;
        while(r - l > 1) {
            k = k1 = 0;
            mid = (r+l)>>1;
            for (int i = 0 ; i < n ; i++) k += a[i]/mid; //用除的找出有多少雙筷子
            for (int i = 0 ; i < n ; i++) k1 += a[i]/(mid+1);
            if (k >= m && k1 < m) break;
            else if (k >= m && k1 >= m) l = mid;
            else if (k < m) r = mid;
        }
        cout << mid << '\n';
    }
    return 0;
}