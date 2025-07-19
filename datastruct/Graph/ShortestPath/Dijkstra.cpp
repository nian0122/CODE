/**
 * @brief Dijkstra最短路径算法实现
 * 
 * 使用邻接矩阵表示图，计算从源点到所有其他顶点的最短路径
 * 
 * @param n 图中顶点数量
 * @param MGraph 图的邻接矩阵表示，MGraph[i][j]表示顶点i到j的边权值
 * @param v0 源点（起始顶点）的索引
 * @param dist 输出参数，存储从源点到各顶点的最短距离
 * @param path 输出参数，存储最短路径的前驱顶点，用于回溯路径
 * 
 * @note 时间复杂度: O(n^2)，适合稠密图
 *       使用INF(INT_MAX)表示两个顶点之间没有直接边
 */
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

const int INF = INT_MAX;  // 表示无穷大，用于不连通的顶点

void Dijkstra(int n, const vector<vector<int>>& MGraph, int v0, 
             vector<int>& dist, vector<int>& path) {
    vector<int> set(n, 0);  // 标记顶点是否已找到最短路径
    int min, v;  // min: 当前找到的最小距离，v: 当前处理的顶点

    // 初始化阶段：设置源点到各顶点的初始距离
    for (int i = 0; i < n; ++i) {
        dist[i] = MGraph[v0][i];  // 初始距离为源点直接到各顶点的距离
        if (MGraph[v0][i] < INF) {
            path[i] = v0;  // 如果有直接路径，前驱设为源点
        } else {
            path[i] = -1;   // 否则设为-1表示不可达
        }
    }
    
    set[v0] = 1;    // 标记源点已处理
    path[v0] = -1;  // 源点没有前驱顶点

    // 主循环：每次找到一个顶点的最短路径
    for (int i = 0; i < n-1; ++i) {
        min = INF;
        // 步骤1：在未处理的顶点中找到距离源点最近的顶点
        for (int j = 0; j < n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                v = j;
                min = dist[j];
            }
        }
        
        set[v] = 1;  // 标记该顶点已处理

        // 步骤2：通过新找到的顶点更新其他顶点的距离
        for (int j = 0; j < n; ++j) {
            if (set[j] == 0 && dist[v] + MGraph[v][j] < dist[j]) {
                dist[j] = dist[v] + MGraph[v][j];  // 更新最短距离
                path[j] = v;                       // 更新前驱顶点
            }
        }
    }
}

/**
 * @brief 测试Dijkstra算法
 * 
 * 使用一个包含5个顶点的图进行测试，输出各顶点的最短距离和路径
 */
int main() {
    const int n = 5;
    // 邻接矩阵表示的图
    vector<vector<int>> graph = {
        {0,   10,  INF, 30,  100},  // 顶点0的边
        {INF, 0,   50,  INF, INF},  // 顶点1的边  
        {INF, INF, 0,   INF, 10},   // 顶点2的边
        {INF, INF, 20,  0,   60},   // 顶点3的边
        {INF, INF, INF, INF, 0}     // 顶点4的边
    };
    
    vector<int> dist(n);  // 存储最短距离
    vector<int> path(n);  // 存储路径前驱

    // 计算从顶点0到所有其他顶点的最短路径
    Dijkstra(n, graph, 0, dist, path);

    // 输出结果
    cout << "Dijkstra算法测试结果：" << endl;
    cout << "顶点\t距离\t路径" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" 
             << (dist[i] == INF ? "∞" : to_string(dist[i])) << "\t" 
             << path[i] << endl;
    }
    
    return 0;
}

