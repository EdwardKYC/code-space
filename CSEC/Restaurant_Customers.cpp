#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> p;

    // 讀取每位顧客的到達和離開時間
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, 1});  
        p.push_back({b, -1}); 
    }

    sort(p.begin(), p.end());

    int c = 0;
    int mc = 0;

    for (auto event : p) {
        c += event.second;
        mc = max(mc, c);
    }

    cout << mc << '\n';

    return 0;
}
