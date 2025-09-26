#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long** matMul(long long**, long long**, long long);
long long** fastMatMul(long long**, long long, long long);
void rlsMem(long long**, int);
int main() {
    long long** A = new long long*[3];
    for (int i = 0; i < 3; i++) {
        A[i] = new long long[3];
    }
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 1;
    A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;

    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        long long year;
        cin >> year;

        if (year == 1) {
            cout << 1 << endl;
        } else if (year == 2) {
            cout << 12 << endl;
        } else if (year == 3) {
            cout << 13 << endl;
        } else {
            long long** result = fastMatMul(A, year - 3, mod);

            long long ans = (13 * result[0][0] + 12 * result[0][1] + result[0][2]) % mod;
            cout << ans << endl;

            rlsMem(result, 3);
        }
    }

    rlsMem(A, 3);
    return 0;
}

long long** matMul(long long** A, long long** B, long long mod) {
    long long** result = new long long*[3];
    for (int i = 0; i < 3; i++) {
        result[i] = new long long[3];
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return result;
}

long long** fastMatMul(long long** array, long long power, long long mod) {
    long long** result = new long long*[3];
    for (int i = 0; i < 3; i++) {
        result[i] = new long long[3];
        for (int j = 0; j < 3; j++) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }

    long long** base = new long long*[3];
    for (int i = 0; i < 3; i++) {
        base[i] = new long long[3];
        for (int j = 0; j < 3; j++) {
            base[i][j] = array[i][j];
        }
    }

    while (power > 0) {
        if (power % 2 == 1) {
            long long** temp = matMul(result, base, mod);
            rlsMem(result, 3);
            result = temp;
        }
        long long** temp = matMul(base, base, mod);
        rlsMem(base, 3);
        base = temp;
        power /= 2;
    }

    rlsMem(base, 3);
    return result;
}

void rlsMem(long long** array, int size) {
    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }
    delete[] array;
}
