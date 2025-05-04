#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>
#define vll vector<long long int>
#define ALL(x) x.begin() , x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; 
    cin >> n;
    for (int i = 0; i <= n; i++) {
        printf("2^%d = %d\n", i, (1 << i));
    }
    return 0;
}