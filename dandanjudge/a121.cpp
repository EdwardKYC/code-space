#include <bits/stdc++.h> 
using namespace std;
#define ll long long 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n , k; cin >> n >> k;
    vector<ll> v(n+1); v[0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    ll l = 0 , r = 1e16;
    while (r - l > 1) {
        ll m = (r+l)>>1;
        ll cnt = 0;//所有小於m的區間和
		int fr = 1, fl = 0;
		for (; fr <= n ; fr ++){
			while (v[fr] - v[fl] >= m){
				fl++;
			}
			cnt += fr - fl;
		}
		if (cnt >= k) r = m;
		else l = m;
    }
    ll cnt = 0;
	int fr = 1, fl = 0;
	for (; fr <= n; fr ++){
		while (v[fr] - v[fl] > l){
			fl ++;
		}
		cnt += fr - fl;
	}
	if (cnt < k - 1) l = r;
	cout << l << '\n';
	return 0 ;
}