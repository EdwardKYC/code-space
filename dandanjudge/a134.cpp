#include <iostream>
using namespace std;

bool find(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        if (find(n)) {
            cout << n << " is a prime!" << endl;
        } else {
            cout << n << " is not a prime." << endl;
        }
    }
    return 0;
}