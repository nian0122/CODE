#include <iostream>
#include <vector>
using namespace std;
// 上三角矩阵压缩（行优先）
vector<double> compressUpperTriangular(double** matrix, int n) {
    vector<double> compressed(n*(n+1)/2);
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            int index = i*(2*n - i + 1)/2 + (j - i);
            compressed[index] = matrix[i][j];
        }
    }
    return compressed;
}

// 上三角矩阵解压
double** decompressUpperTriangular(const vector<double>& compressed, int n) {
    double** matrix = new double*[n];
    for(int i=0; i<n; ++i) {
        matrix[i] = new double[n]{0}; // 初始化为0
        for(int j=i; j<n; ++j) {
            int index = i*(2*n - i + 1)/2 + (j - i);
            matrix[i][j] = compressed[index];
        }
    }
    return matrix;
}