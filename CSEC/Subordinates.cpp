#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
struct p{
    int sum = 0;
    vector<p*> subordinates;
};
int count(p *node) {
    if (node == NULL) return 0;
    for (auto & i : node->subordinates) {
        node->sum += count(i) + 1;
    }
    return node->sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<p> v(n);
    for (int i = 1 ; i < n; i++) {
        int x;
        cin >> x;
        v[x - 1].subordinates.push_back(&v[i]);
    }
    count(&v[0]);
    for (auto & i : v) {
        cout << i.sum << " ";
    }
    return 0;
}