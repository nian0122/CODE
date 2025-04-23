#include <iostream>
#include <vector>
using namespace std;

// 三对角矩阵压缩
vector<double> compressTridiagonal(double** matrix, int n) {
    vector<double> compressed(3*n - 2);
    for(int i=0; i<n; ++i) {
        // 主对角线
        compressed[n-1 + i] = matrix[i][i];
        // 下对角线（i>=1）
        if(i > 0) compressed[i-1] = matrix[i][i-1];
        // 上对角线（i<=n-2）
        if(i < n-1) compressed[2*n-1 + i] = matrix[i][i+1];
    }
    return compressed;
}

// 三对角矩阵解压
double** decompressTridiagonal(const vector<double>& compressed, int n) {
    double** matrix = new double*[n];
    for(int i=0; i<n; ++i) {
        matrix[i] = new double[n]{0}; // 初始化为0
        // 主对角线
        matrix[i][i] = compressed[n-1 + i];
        // 下对角线
        if(i > 0) matrix[i][i-1] = compressed[i-1];
        // 上对角线
        if(i < n-1) matrix[i][i+1] = compressed[2*n-1 + i];
    }
    return matrix;
}

// 矩阵打印函数
void printMatrix(double** matrix, int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            printf("%-4.0f", matrix[i][j]);
        }
        cout << endl;
    }
}

int main() {
    const int n = 4;
    
    // 创建测试矩阵
    double** triMatrix = new double*[n] {
        new double[n]{2,1,0,0},
        new double[n]{3,4,2,0},
        new double[n]{0,5,6,3},
        new double[n]{0,0,7,8}
    };

    cout << "原始三对角矩阵：" << endl;
    printMatrix(triMatrix, n);
    
    // 压缩矩阵
    vector<double> compressed = compressTridiagonal(triMatrix, n);
    
    cout << "\n压缩数组：[";
    for(auto num : compressed) cout << num << " ";
    cout << "]" << endl;

    // 解压验证
    double** decompressed = decompressTridiagonal(compressed, n);
    cout << "\n解压恢复矩阵：" << endl;
    printMatrix(decompressed, n);

    // 释放内存
    for(int i=0; i<n; ++i) {
        delete[] triMatrix[i];
        delete[] decompressed[i];
    }
    delete[] triMatrix;
    delete[] decompressed;

    return 0;
}
