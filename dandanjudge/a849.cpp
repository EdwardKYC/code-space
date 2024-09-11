#include <bits/stdc++.h>
using namespace std ;

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t ;
	long long x1 , x2 , x3 , y1 , y2 , y3 , ans = 0 ;
		while (cin >> t) {
		for (int i = 0 ; i < t ; i++) {
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
			ans = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3 ;
			if (ans < 0)
				ans = -1 * ans ;
			cout << ans << '\n' ;
			}
		}	
   	return 0 ;
}