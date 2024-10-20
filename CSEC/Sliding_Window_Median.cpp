#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k , n;
    cin >> n >> k;
    vll v(n);
    for (auto &i : v)cin >> i;
    multiset<int> st;
    auto mid = st.begin();
    for (int i = 0; i < k; i++) {
        st.insert(v[i]);
    }
    auto mid_it = next(st.begin(), k / 2);
    if (k % 2 == 0) mid_it--;
    cout << *mid_it << " ";
    for (int i = k; i < n; i++) {
        st.insert(v[i]);
        if (v[i] < *mid_it) mid_it--;
        if (v[i - k] <= *mid_it) mid_it++;
        st.erase(st.lower_bound(v[i - k]));
        cout << *mid_it << " ";
    }
    return 0;
}