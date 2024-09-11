#include<bits/stdc++.h>
using namespace std ;
int main () {
	cin.tie(NULL),ios::sync_with_stdio(false);
	int n , c ; 
	while (cin >> n >> c ) {
		int a[n+1] , b[n+1] , k[n+1] , dp[c+1];
		a[0] = 0 ;
		b[0] = 0 ;
		k[0] = 0 ;
		for (int i = 0 ; i <= c ; i++) 
			dp[i] = 0 ;
			
		for (int i = 1 ; i <= n ; i++)
			cin >> a[i] >> b[i] >> k[i] ;
			
		for (int i = 0; i <= n; i++) cout << a[ i ] << ' ' << b[ i ] << ' ' << k[ i ] << endl;;
		cout << endl;
		
		for (int i = 1 ; i <= n ; i++){
			int w , v , K;
			K = k[i] ;
			cout << "K = " << K << endl;
			for(int t = 1 ; t <= K ; t *= 2) {
				cout << "(" << i << ", " << t << ") : " << K << endl;
				K -= t ;
				w = t * b[i] ;
				v = t * a[i] ;
				for (int j = c ; j >= w ; j--)
					dp[j] = max (dp[j] , dp[j-w] + v) ;	
			}
			w = K * b[i] ;
			v = K * a[i] ;
			for (int j = c ; j >= w ; j--)
				dp[j] = max (dp[j] , dp[j-w] + v) ;
		}
		cout << dp[c] << '\n';
	}
return 0;
}

