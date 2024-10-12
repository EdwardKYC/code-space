#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
struct range
{
    int x , y , idx;
};
int lowbit(int x) {
    return x & (-x);
}
bool cmp(range a , range b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
class BIT {
    vector<int> bit;
    int n;

public:
    BIT(int size) {
        n = size;
        bit.resize(n + 1, 0); // 初始化大小為 n+1
    }

    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += lowbit(idx); // 向上更新
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= lowbit(idx); // 向前查詢
        }
        return sum;
    }

    // 查詢大於等於 y 的數量
    int greater_query(int y) {
        return query(n) - query(y - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<range> v(n);
    vector<int> arr_y(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
        arr_y[i] = v[i].y;
    }

    sort(arr_y.begin(), arr_y.end());
    sort(v.begin(), v.end(), cmp);

    BIT bit(n);
    for (int i = 0; i < n; i++) {
        bit.update(i + 1, 1); // 假設你要對索引 i+1 更新值
    }

    vector<int> a1(n, 0);
    vector<int> a2(n, 0);

    for (int i = 0; i < n; i++) { // 被包含
        a1[i] = bit.greater_query(v[i].y);
    }

    for (int i = n - 1; i >= 0; i--) { // 包含
        a2[i] = bit.greater_query(v[i].y);
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
