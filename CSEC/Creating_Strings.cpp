#include <bits/stdc++.h>
using namespace std;
int main () {
    string str;
    cin >> str;
    int ans = 1 , temp = 1; 
    sort(str.begin() , str.end());
    for (int i = 1 , j = 2; i <= str.size(); i++) {
        ans *= i;
        if (str[i] == str[i-1]) {
            temp *= j;
            j++;
        }
        else 
            j = 2;
    }
    cout << ans/temp << '\n';
    do{
        cout << str << '\n';
    }while (next_permutation(str.begin() , str.end()));
    return 0;
}