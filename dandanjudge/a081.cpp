#include<bits/stdc++.h>
using namespace std;
#define pii pair<int , int>
bool cmp(pii a , pii b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}
int main () {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<pii> v(n);
        priority_queue<int , vector<int> , greater<int>> m;

        for (int i = 0 ; i < n ; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin() , v.end() , cmp);        
        int ans = 0 , t = 0 , idx = 0;

        while (idx < n || !m.empty()) {
            if (m.empty() && t < v[idx].first) t = v[idx].first;//場上沒有地鼠所以直接跳到下一個地鼠出現的時間
            while (idx < n && t >= v[idx].first) {//把這個時間會出現的地鼠都叫出來
                m.push(v[idx].second);
                idx++;
            }
            if (!m.empty() && t <= m.top()) {
                m.pop();
                ans++;
                t++;
            }
            else if (!m.empty() && t > m.top()) m.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}