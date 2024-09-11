#include <bits/stdc++.h>
using namespace std;
int main () {
    int n , m;
    double s;
    string ans;
    while (cin >> n >> m >> s) {
        vector <string> v(n);
        double k = 0 , all = 0 , maxs = 0;
        cin >> ans;
        for (int i = 0; i < n; i++) cin >> v[i];

        for (int i = 0; i < n; i++) {
            k = 0;
            for (int j = 0; j < m; j++) {
                if (v[i][j] == ans[j]) k += s;
            }
            all += k;
            maxs = max(maxs, k);
        } 
        cout << fixed << setprecision(4) << maxs << '\n' << fixed << setprecision(4) << all/n << '\n';
    }
    return 0;
}