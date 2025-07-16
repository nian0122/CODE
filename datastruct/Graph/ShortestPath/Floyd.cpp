/**
 * Floyd-Warshall 最短路径算法实现
 * 计算图中所有顶点对之间的最短路径
 * 
 * 时间复杂度: O(V^3)
 * 空间复杂度: O(V^2)
 * 可以处理负权边(但不能有负权环)
 */

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX / 2; // 避免溢出

/**
 * Floyd-Warshall 算法实现
 * @param graph 图的邻接矩阵表示
 * @return 包含所有顶点对最短距离的矩阵
 */
vector<vector<int>> floydWarshall(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph; // 初始化距离矩阵
    
    // 核心算法：三重循环
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 松弛操作
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    return dist;
}

/**
 * 打印最短路径矩阵
 */
void printSolution(const vector<vector<int>>& dist) {
    int n = dist.size();
    cout << "所有顶点对之间的最短距离矩阵:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

/**
 * 测试 Floyd-Warshall 算法
 */
int main() {
    // 示例图
    const int V = 4;
    vector<vector<int>> graph = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    
    // 计算所有顶点对最短路径
    vector<vector<int>> dist = floydWarshall(graph);
    
    // 打印结果
    printSolution(dist);
    
    return 0;
}