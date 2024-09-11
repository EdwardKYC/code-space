#include <bits/stdc++.h>
using namespace std;
bool cmp (pair<int , int> a , pair<int , int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	cin.tie(NULL) -> ios::sync_with_stdio(false);
	int t , n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector< pair<int , int> > v(n);
		for (int i = 0 ; i < n ; i++) {
			cin >> v[i].first >> v[i].second;
		}
		sort (v.begin() , v.end() , cmp);
		int ans = 1 , idx = 1 , time = v[0].second;
		while (idx < n) {
			if (time > v[idx].first) idx++;
			else if (time <= v[idx].first) {
				ans++;
				time = v[idx].second;
				idx++;
			}	
		}
		cout << ans << '\n';
	}
	return 0;
}
