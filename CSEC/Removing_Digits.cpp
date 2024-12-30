#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
int funtion(int n) {
    int ans = 0;
    while (n != 0) {
        string str = to_string(n);
        int temp = 0;
        for (int i = 0; i < str.size(); i++) {
            temp = max(temp , str[i] - '0');
        }
        n -= temp;
        ans++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << funtion(n);
    return 0;
}