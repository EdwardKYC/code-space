#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    vector<int> set1, set2;
    sum /= 2;

    // 貪心分割法，從大到小分配數字
    for (int i = n; i >= 1; i--) {
        if (sum >= i) {
            set1.push_back(i);
            sum -= i;
        } else {
            set2.push_back(i);
        }
    }

    // 輸出結果
    cout << set1.size() << '\n';
    for (int i = set1.size()-1; i >= 0; i--) {
        if (i == 0) 
             cout << set1[i] << '\n';
        else 
            cout << set1[i] << " ";
    }

    cout << set2.size() << '\n';
    for (int i = set2.size()-1; i >= 0; i--) {
        if (i == 0) 
             cout << set2[i] << '\n';
        else 
            cout << set2[i] << " ";
    }

    return 0;
}