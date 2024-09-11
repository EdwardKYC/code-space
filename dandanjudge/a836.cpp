#include <bits/stdc++.h>
using namespace std ;
int main () {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t , n;
	cin >> t;
	for (int i = 0 ; i < t ; i++) {
		cin >> n; 
		double k , m , l = 5.1 , r = 14;
		int j = 30;
		while (j--) {
			m = (l + r)/2;
			k = pow(m , m);
			if (k == n) break;
			else if (k < n) l = m;
			else if (k > n) r = m;
		}
		cout << m << '\n';
	}	
	return 0 ;
}