#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
void merge(vector<int> &v , ll &ans) {
	ll s = v.size();
	if (s == 1) return;
	ll m = s >> 1;
	vector<int> l(v.begin() , v.begin()+ m) , r(v.begin()+m , v.end());
	merge(l , ans);
	merge(r , ans);
	ll a = 0 , b = 0 , n = 0 , ls = l.size() , rs = r.size();
	while (a < ls && b < rs) {
		if(l[a] > r[b]) {
	    	v[n] = r[b];
			b++;
			n++;
			ans += ls - a;
		}
		else {
			v[n] = l[a];
			a++;
			n++;
		}
	}
	while (a < ls) {
		v[n] = l[a];
		a++;
		n++;
	}
	while (b < rs) {
		v[n] = r[b];
		b++;
		n++;
	}
	r.clear() , l.clear () ;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n , t;
	cin >> t;
	for (ll j = 0 ; j < t ; j++) {
		cin >> n;
		vector<int> v(n);
		for (ll i = 0 ; i < n ; i++) {
			cin >> v[i];
		}
		ll ans = 0;
		merge(v , ans) ;
		cout << ans << '\n';
	}	
	return 0 ;
}