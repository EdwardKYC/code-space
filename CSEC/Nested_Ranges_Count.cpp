#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
struct range
{
    int x , y , idx;
};
bool cmp(range a , range b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<range> v(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
    }
    sort(v.begin() , v.end() , cmp);
    vector<int> a1(n , 0);
    vector<int> a2(n , 0);
    for (int i = 0; i < n; i++) {//被包含
        
    }
    for (int i = n - 1; i >= 0; i--) {//包含
        
    }
    for (int i = 0; i < n; i++) {
        cout << a2[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << a1[i] << " ";
    }
    return 0;
}