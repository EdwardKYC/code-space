#include <stdio.h>

int main() {
    char discard;  // 用來丟棄非數字的字符
    long long num1, num2, num3, num4, num5;

    // 使用scanf逐一讀取，並使用%lld來讀取long long類型的數字
    scanf("NCKU%lld%c%lld%c%lld%c%lld%c%lld", &num1, &discard, &num2, &discard, &num3, &discard, &num4, &discard, &num5);

    // 輸出結果，去掉前導零
    printf("\"%lld\" \"%lld\" \"%lld\" \"%lld\" \"%lld\"\n", num1, num2, num3, num4, num5);

    return 0;
}
