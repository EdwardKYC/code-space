#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, vector<pii>> sum_pairs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum_pairs[a[i] + a[j]].push_back({i, j});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = x - a[i] - a[j];
            if (sum_pairs.find(target) != sum_pairs.end()) {
                for (auto &p : sum_pairs[target]) {
                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}
