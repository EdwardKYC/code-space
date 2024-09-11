#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        if (input == "Neko我婆") {
            cout << "Neko我婆" << '\n' << "[該用戶已被禁言]" << endl;
        } else if (input == "Neko我婆#ΦωΦ") {
            cout << "[無法讀取此訊息]" << '\n' << "佑仔在你後面，他很生氣>:(" << endl;
        } else if (input == "Neko超棒的啦") {
            cout << "Neko超棒的啦\\ΦωΦ/" << endl;
        } else {
            cout << input << "#ΦωΦ" << endl;
        }
    }
    return 0;
}