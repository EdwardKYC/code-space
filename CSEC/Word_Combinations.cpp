#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()
const int mod = 1e9 + 7;
struct node {
    node *next[26];
    bool isEnd;

    node() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};
node *root = new node();
void insert(string &t) {
    node* cur = root;
    for (char c : t) {
        int idx = c - 'a';
        if (cur->next[idx] == nullptr) {
            cur->next[idx] = new node();
        }
        cur = cur->next[idx];
    }
    cur->isEnd = true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.size() , k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;
        insert(t);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1; 
    for (int i = 0; i <= n; i++) {
        if (dp[i] == 0) continue; 
        node* cur = root;
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if (cur->next[idx] == nullptr) break;
            cur = cur->next[idx];
            if (cur->isEnd) {
                dp[j+1] = (dp[j+1] + dp[i]) % mod;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}