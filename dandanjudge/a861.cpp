#include <bits/stdc++.h>
using namespace std ;
int main () {
	cin.tie(NULL),ios::sync_with_stdio(false);
	int t , n , ans , a ;
	while (cin >> t) {
		for (int i = 0 ; i < t ; i ++) {
			cin >> n ;
			a = 0 ;
		    while (n > 7) {
		    	if (n % 2 == 0)
		    	    a++ ;
		    	if (n % 3 == 0)
		    	    a++ ;
		    	n -= 7 ;
			}
			if (n == 1 || n == 5)
				cout << a << '\n' ;
			else if (n == 2 || n == 3 || n == 4 || n == 7)
				cout << a+1 << '\n' ;
			else if (n == 6)
				cout << a+2 << '\n' ;	
		}
    }
	return 0 ;
}
