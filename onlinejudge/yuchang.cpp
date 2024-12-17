#include <iostream>
#include <vector>
#include <chrono> // 用於計時

using namespace std;

// 記錄函數調用次數
int function_calls = 0;

// 計算次方的簡單函數
int power(int base, int exp) {
    int result = 1;
    while (exp--) {
        result *= base;
    }
    return result;
}

// 計算行列式的函數
double Determinant(vector<vector<double>>& A, int dim) {
    function_calls++; // 記錄函數被調用次數

    if (dim == 1) {
        return A[0][0];
    }
    if (dim == 2) {
        // 計算二階行列式直接返回結果
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }

    double det = 0.0;
    for (int i = 0; i < dim; i++) {
        // 創建子矩陣
        vector<vector<double>> subMatrix(dim - 1, vector<double>(dim - 1));
        for (int j = 1; j < dim; j++) {
            int colIdx = 0;
            for (int k = 0; k < dim; k++) {
                if (k == i) continue;
                subMatrix[j - 1][colIdx] = A[j][k];
                colIdx++;
            }
        }

        // 使用遞迴計算子矩陣的行列式
        det += A[0][i] * power(-1, i) * Determinant(subMatrix, dim - 1);
    }
    return det;
}

int main() {
    // 測試用例：11x11 矩陣
    vector<vector<double>> matrix = {
        {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {10, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2},
        {9, 10, 11, 10, 9, 8, 7, 6, 5, 4, 3},
        {8, 9, 10, 11, 10, 9, 8, 7, 6, 5, 4},
        {7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5},
        {6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6},
        {5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7},
        {4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8},
        {3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9},
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    };

    int dim = 11; // 矩陣維度

    // 開始計時
    auto start = chrono::high_resolution_clock::now();

    // 計算行列式
    double det = Determinant(matrix, dim);

    // 結束計時
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    // 輸出結果
    cout << "Determinant: " << det << endl;
    cout << "Function calls: " << function_calls << endl;
    cout << "Execution time: " << elapsed.count() << " seconds" << endl;

    return 0;
}
