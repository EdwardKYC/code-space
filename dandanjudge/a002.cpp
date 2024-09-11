#include <bits/stdc++.h>
using namespace std;
long long m(long long a , long long b) {
    long long k = pow(10 , b);
    return (a / k) % 10;
}
int main () {
    long long nationalID;
    int v[26] = {10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,34 ,18 ,19 ,20 ,21 ,22 ,35 ,23 ,24 ,25 ,26 ,27 ,28 ,29 ,32 ,30 ,31 ,33};
    while (cin >> nationalID) {
        int english[26] = {0};
        long long c = nationalID % 10;
        for (int i = 0; i < 26; i++) {
            long long s = v[i] / 10 + ( v[i] % 10 ) * 9;
            for (int j = 0; j < 8; j++) {
                s += m(nationalID , j+1) * (j+1);
            }
            s %= 10;
            if (10 - s == c)
                english[i]++;
        }
        for (int i = 0; i < 26; i++) {
            if (english[i] != 0)
                cout << char(i+65);
        }
        cout <<'\n';
    }
    return 0;
}