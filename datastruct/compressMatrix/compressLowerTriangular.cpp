#include <iostream>
#include <vector>
using namespace std;

// 下三角矩阵压缩（行优先）
vector<double> compressLowerTriangular(double** matrix, int n) {
    vector<double> compressed(n*(n+1)/2+1);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<=i; ++j) {
            int index = i*(i+1)/2 + j;
            compressed[index] = matrix[i][j];
        }
    }
    compressed[n*(n+1)/2] = matrix[0][n-1];
    return compressed;
}

// 下三角矩阵解压
double** decompressLowerTriangular(const vector<double>& compressed, int n) {
    double** matrix = new double*[n];
    for(int i=0; i<n; ++i) {
        matrix[i] = new double[n]{0}; // 初始化为0
        for(int j=0; j<=i; ++j) {
            int index = i*(i+1)/2 + j;
            matrix[i][j] = compressed[index];
        }
    }
    return matrix;
}


