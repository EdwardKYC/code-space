#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin() , x.end()
struct range {
    int x , y , idx;
};
bool cmp (range a , range b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int main () {
    int n;
    cin >> n;
    vector<range> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
    }    
    sort(ALL(v) , cmp);
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 優先隊列 (離開時間, 房間號)
    int room = 0, max_room = 0;   
    for (int i = 0; i < n; i++) {
        int arrival = v[i].x , departure = v[i].y;
        if (!pq.empty() && pq.top().first < arrival) {
            room = pq.top().second;
            pq.pop();
            ans[v[i].idx] = room;
            pq.push({departure, room});
        } else {
            max_room++;
            room = max_room;
            ans[v[i].idx] = room;  
            pq.push({departure, room});
        }
    }
    cout << max_room << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
