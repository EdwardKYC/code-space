#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
struct Compare {
    bool operator()(const pii& p1, const pii& p2) {
        return p1.second < p2.second;
    }
};
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n , t , e;
    while (cin >> n) {
        if (n == 0) break;
        priority_queue<pii, vector<pii>, Compare> pq;
        for (int i = 0; i < n;i++) {
            cin >> t >> e;
            pq.push(make_pair(t , e));
        }   
        long long dt = 0 , et = 0;
        while(!pq.empty()) {
            if (dt == 0 && et == 0) {
                dt = pq.top().first;
                et = dt + pq.top().second;
            }
            else {
                if ((dt+pq.top().first+pq.top().second) <= et){
                    dt += pq.top().first;
                }
                else if ((dt+pq.top().first+pq.top().second) > et) {
                    et = dt+pq.top().first+pq.top().second;
                    dt += pq.top().first;
                }
            }
            pq.pop();s
        } 
        cout << et << '\n';    
    }
    return 0;
}