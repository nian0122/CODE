#include <iostream>
#include <vector>
using namespace std;

// 压缩函数：将n阶对称矩阵压缩为下三角数组
vector<double> compressSymmetricMatrix(double** matrix, int n) {
    int size = n * (n + 1) / 2;
    vector<double> compressed(size);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            int index = i * (i + 1) / 2 + j; // 压缩位置计算公式
            compressed[index] = matrix[i][j];
        }
    }
    return compressed;
}

// 解压函数：将压缩数组还原为对称矩阵
double** decompressSymmetricMatrix(const vector<double>& compressed, int n) {
    double** matrix = new double*[n];
    for(int i = 0; i < n; ++i) {
        matrix[i] = new double[n](); // 初始化为0
    }
    
    // 先填充下三角部分
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            int index = i * (i + 1) / 2 + j;
            matrix[i][j] = compressed[index];
        }
    }
    
    // 填充上三角部分
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            matrix[i][j] = matrix[j][i]; // 确保下三角已初始化
        }
    }
    return matrix;
}

// 打印矩阵
void printMatrix(double** matrix, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // 创建示例对称矩阵
    const int n = 4;
    double** symMatrix = new double*[n];
    for(int i = 0; i < n; ++i) {
        symMatrix[i] = new double[n];
        for(int j = 0; j < n; ++j) {
            symMatrix[i][j] = (i >= j) ? i*10 + j : j*10 + i;
        }
    }
    
    cout << "原始对称矩阵：" << endl;
    printMatrix(symMatrix, n);
    
    // 压缩矩阵
    vector<double> compressed = compressSymmetricMatrix(symMatrix, n);
    
    cout << "\n压缩数组：";
    for(auto num : compressed) {
        cout << num << " ";
    }
    
    // 解压验证
    double** decompressed = decompressSymmetricMatrix(compressed, n);
    cout << "\n\n解压恢复矩阵：" << endl;
    printMatrix(decompressed, n);
    
    // 释放内存
    for(int i = 0; i < n; ++i) {
        delete[] symMatrix[i];
        delete[] decompressed[i];
    }
    delete[] symMatrix;
    delete[] decompressed;
    
    return 0;
}
