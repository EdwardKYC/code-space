#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vll v(n);
    for (auto &i : v)cin >> i;
    stack<int> st; 

    for (int i = 0; i < n; i++) {

        while (!st.empty() && v[st.top()] >= v[i]) {
            st.pop();
        }
        if (st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top() + 1 << " ";
        }
        st.push(i);
    }  
    return 0;
}