#include <iostream>
using namespace std;

int main() {
    long long  n;
    cin >> n;
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0 || n == 1) {
        cout << "Kaohsiung FaDaTsai" << endl;
    } else {
        cout << "PaShu go go go~" << endl;
    }
    return 0;
}