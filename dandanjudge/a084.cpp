#include <iostream> 
#include <vector>
using namespace std ;
#define ll long long 
void merge(vector<ll> &v) {
	ll s = v.size();
	if (s == 1) return;
	ll m = s >> 1;
	vector<ll> l(v.begin() , v.begin()+ m) , r(v.begin()+m , v.end());
	merge(l);
	merge(r);
//	l.push_back(9223372036854775807);
//	r.push_back(9223372036854775807);
	ll a = 0 , b = 0 , n = 0 , ls = l.size() , rs = r.size();
	while (a < ls && b < rs) {
		if(l[a] < r[b]) {
			v[n] = l[a];
			a++;
			n++;
		}
		else {
			v[n] = r[b];
			b++;
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
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	while (cin >> n) {
		vector<ll> v(n);
		for (int i = 0 ; i < n ; i++) {
			cin >> v[i];
		}
		
		merge(v) ;
		for (int i = 0 ; i < n ; i++) {
			if(i != n-1) cout << v[i] << " ";  
			else cout << v[i] ;
		}
		cout << '\n';
	}
	return 0 ;
}