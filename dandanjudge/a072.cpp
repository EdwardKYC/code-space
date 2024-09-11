#include<bits/stdc++.h>
using namespace std;
#define pii pair<int , int>
void f(vector<int> v , int a[] , int k) {
    for (int i = 0 ; i < n ; i++) {
        if (v[i] % k == 0){
            
        }
    }
}
int main () {
    cin.tie(NULL) -> ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> v[i];
        }
        int a[9];
        for (int i = 10 ; i < 9 ; i = i*10) {
            f(v , a , i);
        }
        cout << '\n';
    }
    return 0;
}