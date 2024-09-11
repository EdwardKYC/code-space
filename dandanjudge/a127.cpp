#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

int main() {
    double a,b,p,c,d,q,x,y;
    int k = 0;
    while (cin >> a >> b >> p >> c >> d >> q) {
        k++;
        x = (d*p-b*q)/(a*d-b*c);
        y = (c*p-a*q)/(b*c-a*d);
        cout << "case: " << k << '\n' ;
        cout << "x = " << fixed << setprecision(2) << round(x * 100) / 100 << '\n' ;
        cout << "y = " << fixed << setprecision(2) << round(y * 100) / 100 << '\n' ;
        cout <<'\n'; 
    }
    return 0;
}