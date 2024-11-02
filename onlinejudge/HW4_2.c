#include <stdio.h>
#include <string.h>

int binary(char s[100]){
    int k = 1;
    int ans = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '1') ans += k;
        k = k << 1;
    }
    return ans;
}
int main() {
    int n;
    char s[100];
    scanf("%s", s);
    n = binary(s);
    float *floatPtr = (float *)&n;
    printf("%.23e\n", *floatPtr);

    return 0;
}