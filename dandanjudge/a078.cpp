#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp (pair<int , int> a , pair<int , int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	cin.tie(NULL) -> ios::sync_with_stdio(false);
	int T , n; 
	cin >> T;
	while (T--) {
		cin >> n;
		vector< pair<int , int> > v(n);
		for (int i = 0 ; i < n ; i++) cin >> v[i].first >> v[i].second;
		sort (v.begin() , v.end() , cmp);
		int ans = 0 , t = 0; 
		priority_queue<int> pq;
		for(int i = 0 ; i < n ; i++) {
			if (t <= v[i].second - v[i].first) {
				t += v[i].first;
				pq.push(v[i].first);
				ans++;	
			}
			else if (t > v[i].second - v[i].first) {
				if (!pq.empty() && pq.top() > v[i].first) {
                    t = t - pq.top() + v[i].first;
                    pq.pop();
                    pq.push(v[i].first);
                }
			}
		}
		cout << ans << '\n';
	}
	return 0;
}