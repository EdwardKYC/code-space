#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    set<int> light;
    light.insert(0); 
    light.insert(x);
    
    multiset<int> without;
    without.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = light.lower_bound(p);
        int right = *it;
        it--;
        int left = *it;
        light.insert(p);
        without.erase(without.find(right - left));
        without.insert(p - left);
        without.insert(right - p);
        cout << *without.rbegin() << " ";
    }
    
    return 0;
}
