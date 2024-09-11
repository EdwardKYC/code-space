#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n , k , l = 0 , r = 1;
    cin >> n >> k;
    vector<int> a(n+1); 
    a[n] = 0;
    for (int i = 0 ; i < n ; i++)   cin >> a[i];
    for (int i = n-2 ; i >= 0 ; i--)    a[i] += a[i+1];
    int d = a[0] - a[1];     //     3  6  1  7 2 4
    while (l < n && r <= n && r > l) {//10  23 20 14 13 6 4 0
        d = a[l] - a[r];
        if (d < k && r != n){
            r++;
        }
        else if (d < k && r == n){
            for (int i = l ; i < n ; i++) {
                a[i] = n;
            }
            break;
        }
        else if (d == k) {
            a[l] = r;
            l++;
        }
        else {
            a[l] = r-1;
            l++;
        }
    }
    a[n-1] = n;
    for (int i = 0 ; i < n ; i++) {
		if(i != n-1) cout << a[i] << " ";  
		else cout << a[i] << '\n';
	}
return 0;
}