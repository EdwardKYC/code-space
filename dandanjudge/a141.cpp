#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    double t = 1222, combo = 0, n = 746031, score = 0;
    while (t--) {
        cin >> s;
        if (s == "PERFECT") {
            score += (1 * 900000 / 1222) + (combo * 100000 / n);
            combo++;
        } else if (s == "GOOD") {
            score += (0.7 * 900000 / 1222) + (combo * 100000 / n);
            combo++;
        } else if (s == "BAD") {
            score += (0.3 * 900000 / 1222) + (combo * 100000 / n);
            combo = 0;
        } else {
            score += (0 * 900000 / 1222) + (combo * 100000 / n);
            combo = 0;
        }
    }
    score = ceil(score);
    cout << score ;
    return 0;
}