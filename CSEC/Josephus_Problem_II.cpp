#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> ans;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    int idx = 0;
    for (int i = 0; i < n; ++i) {
        idx = (idx + k) % v.size();
        ans.push_back(v[idx]);  
        v.erase(v.begin() + idx);  
    }

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
