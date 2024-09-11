#include <bits/stdc++.h>
using namespace std ;
int main () {
	string s ; 
	int len , d[30] ,f[30] ;
	for (int i = 0 ; i < 30 ; i++)
			f[i] = 0 ;
	cin >> len ;
	cin >> s ;
	string t(s);
	while (s.size() != 0) {
		int b , a = (int)s[0] , k = 0 , D = 1;
		d[0] = (int)s[0] ;
		for (int i = 0 ; i < 30 ; i++)
			f[i] = 0 ;
			
		for (int i = 0 ; i < s.size() ; i++){
			b = (int)s[i] ;
			if (b != a) {
				k++ ;
				a = b ;
				d[D] = (int)s[i] ;
				D++ ;
				f[D-1]++ ;
			}	
		}
		
		if (len % k == 0) {
			for (int i = 0 ; i < k ; i++) {
				for (int j = 0 ; j < k ; j++){
					t[i*j] = (char)d[i] ;
				}
			}
			int d = 0 , dk;
			string S ;
			for (int i = 0 ; i < k ; i++) {
				if (f[i] != k) {
					dk = f[i] - k ;
					if (dk < 0)
						dk = -dk ;
					for (int j = 0 ; j < dk ; j++)	
						S = S + (char)d[i] ;
				}
			}
			cout << k << len << '\n' ;
			s.swap(S);	
			
		} 
		else 
			cout << "william is sad" << '\n' ;
		}
	
	return 0 ;
	
}
