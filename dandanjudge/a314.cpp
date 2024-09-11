#include<bits/stdc++.h>
using namespace std;

bool prime(long long n) {
    if (n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
long long find(long long n) {
    if (n <= 1) return 2;
    if (n == 2) return 3;
    long long next = n + (n % 2 == 0 ? 1 : 2);;
    bool f = false;
    while (!f) {
        if (prime(next)) {
            f = true;
            break ;
        }   
        else
            next += (next % 6 == 1 ? 4 : 2);
    }
    return next;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n;
    while (cin >> n) {
        cout << find(n) << '\n';
        if (cin.eof()) { 
            break;
        }
    }
    return 0;
}