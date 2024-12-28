#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x; // 修正輸入方式

    vector<ll> price(n); // 物品價格
    vector<ll> value(n); // 物品價值
    vector<ll> dp(x + 1, 0); // 初始化 dp，大小為 x + 1

    for (auto &i : price) cin >> i; // 讀取物品價格
    for (auto &i : value) cin >> i; // 讀取物品價值

    for (int i = 0; i < n; i++) { // 遍歷每個物品
        for (int j = x; j >= price[i]; j--) { // 背包容量從大到小
            dp[j] = max(dp[j], dp[j - price[i]] + value[i]); // 狀態轉移方程
        }
    }

    cout << dp[x]; // 輸出最大價值
    return 0;
}
