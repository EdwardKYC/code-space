#include <bits/stdc++.h>
using namespace std;

struct Class {
    int x, y;
    int diff;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int total = N + M;

    vector<Class> classes(total);
    for (int i = 0; i < total; i++) {
        cin >> classes[i].x >> classes[i].y;
        classes[i].diff = classes[i].x - classes[i].y;
    }

    // 差值排序
    sort(classes.begin(), classes.end(), [](const Class &a, const Class &b) {
        return a.diff < b.diff;
    });

    int ans = 0;
    for (int i = 0; i < total; i++) {
        if (i < N) ans += classes[i].x; // 選男生
        else ans += classes[i].y;       // 選女生
    }

    cout << ans << "\n";
    return 0;
}
