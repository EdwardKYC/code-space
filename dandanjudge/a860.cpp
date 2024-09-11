#include <bits/stdc++.h>
using namespace std ;
int main () {
	long long int t , n ,ans ;
	while (cin >> t) {
		for (int i = 0 ; i < t ; i++) {
			cin >> n ; 
			if (n == 2) {
				cout << "2" << '\n';
				cout << "1" << '\n';
			}
			else if (n == 3) {
				cout << "3" << '\n';
				cout << "1" << '\n';
			}
			else if (n % 2 == 1 ) {
				n = n - 3 ;
				ans = n/2 ;
				cout << "2" << " " << "3" << '\n';
				cout << ans << " " << "1" << '\n';
			}
			else if (n % 2 == 0 ) {
				ans = n/2 ;
				cout << "2" << '\n';
				cout << ans << '\n';	
			}
		}
	}
	return 0 ;
}
