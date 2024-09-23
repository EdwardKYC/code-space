#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// 將整數轉換為 n 位的二進位字串
string toBinary(int num, int n) {
    return bitset<16>(num).to_string().substr(16 - n, n); // 將二進制字串截取為 n 位
}

int main() {
    int n;
    cin >> n;

    int total = 1 << n; // 2^n，總共需要生成的 Gray code 個數

    // 生成 Gray code 序列並輸出
    for (int i = 0; i < total; ++i) {
        int gray = i ^ (i >> 1);  // Gray code 計算公式
        cout << toBinary(gray, n) << endl;  // 輸出 n 位的 Gray code
    }

    return 0;
}