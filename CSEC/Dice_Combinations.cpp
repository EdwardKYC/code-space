#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
ll dp[10000001];
void funtion() {
    int temp = 1;
    dp[1] = 1;
    for (int i = 2; i <= 6; i++) {
        temp += dp[i-1];
        dp[i] = temp;
    }
    for (int i = 7; i <= 1e6; i++) {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6]) % mod;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    funtion();
    cout << dp[n];
    return 0;
}