#include<bits/stdc++.h>
using namespace std;
struct f {
	string t;
	int a;
	int b;
	string s;
};
bool cmp(f p, f q) {
	if (p.a == q.a) {
		return p.b < q.b;
	}
	else {
		return p.a < q.a;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<f> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].t >> v[i].a >> v[i].b >> v[i].s;
	}
	sort (v.begin(), v.end(), cmp);
	for (int i = 0;i < n;i++) {
		cout << v[i].a << ' ' << v[i].b << ' ' << v[i].t << '\n' << v[i].s << '\n';
	}
}
