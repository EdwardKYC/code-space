#include <bits/stdc++.h>
#include <stdio.h>
using namespace std ;
int main () {
	cin.tie(NULL),ios::sync_with_stdio(false);
	string s , as ;
	long long int t , a , x , y , ans ; 
	double dx , dy ,dans ;
	while (cin >> s) {
		cin >> t ;
		if (s == "int") {
			for (int i = 0 ; i < t ; i++) {
				cin >> x >> y ;
				ans = x * y ;
				stringstream ss ;
				ss << ans ;
				ss >> as ;
				cout << ans << " " << as.size() << '\n' ;
			}	
		}	
		if (s == "double") {
			for (int i = 0 ; i < t ; i++) {
				cin >> dx >> dy ;
				dans = dx * dy ;
				ans = (long long int)dans ;
				if (dans / ans != 1)
					if(ans > 0)
						ans++ ;
				stringstream ss ;
				ss << ans ;
				ss >> as ;
				cout << ans << " " << as.size() << '\n' ;
			}	
		}
	}
	return 0 ;
}