#include <bits/stdc++.h>
using namespace std;
void move(int n , int begin , int end) {
    if (n != 0) {
        move(n-1 , begin , 6-(end+begin));
        cout << begin << " " << end << '\n';
        move(n-1 , 6-(end+begin) , end);
;    }
    else 
        return;
}
int main () {
    int n ;
    cin >> n;
    cout << pow(2 , n)-1 << '\n';
    move(n , 1 , 3);
}