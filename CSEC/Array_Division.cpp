#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<long long int>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vll v(n);
    ll maxElement = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxElement = max(maxElement, v[i]); 
        sum += v[i];                       
    }
    ll l = maxElement, r = sum;
    ll ans = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll currentSum = 0;
        int count = 1; 
        for (int i = 0; i < n; i++) {
            if (currentSum + v[i] > mid) {                 
                count++;   
                currentSum = v[i]; 
            }
            else currentSum += v[i];
        }
        if (count > k)l = mid + 1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
