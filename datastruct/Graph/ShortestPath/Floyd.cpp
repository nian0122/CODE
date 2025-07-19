/**
 * Floyd-Warshall 最短路径算法实现
 * 计算图中所有顶点对之间的最短路径
 * 
 * 时间复杂度: O(V^3)
 * 空间复杂度: O(V^2)
 * 可以处理负权边(但不能有负权环)
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int INF = INT_MAX / 2; // 避免溢出



void floyd(int n, vector<vector<int>>& graph, vector<vector<int>>& path) {
    vector<vector<int>> dist(n, vector<int>(n));
    
    // 初始化距离矩阵和路径矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            path[i][j] = -1;
        }
    }
    
    // 核心算法：三重循环
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 松弛操作
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

/**
 * 打印路径并计算路径距离
 * @param graph 图的邻接矩阵
 * @param path 路径矩阵
 * @param u 起点
 * @param v 终点
 * @return 路径距离
 */
int printPath(const vector<vector<int>>& graph, const vector<vector<int>>& path, int u, int v) {
    if (path[u][v] == -1) {
      //  cout << u << " -> " << v << " ";
        return graph[u][v];
    } else {
        int mid = path[u][v];
        int dist1 = printPath(graph, path, u, mid);
        int dist2 = printPath(graph, path, mid, v);
        return dist1 + dist2;
    }
}

/**
 * 打印距离矩阵
 * @param graph 图的邻接矩阵
 * @param path 路径矩阵
 */
void printDistanceMatrix(const vector<vector<int>>& graph, const vector<vector<int>>& path) {
    cout << "距离矩阵:" << endl;
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << "0 ";
            } else {
                int dist = printPath(graph, path, i, j);
                cout << dist << " ";
            }
        }
        cout << endl;
    }
}

/**
 * 测试 Floyd 算法
 */
int main() {
    cout << "=== 测试用例1: 基本示例 ===" << endl;
    {
        const int V = 4;
        vector<vector<int>> graph = {
            {0,   5,  INF, 10},
            {INF, 0,   3, INF},
            {INF, INF, 0,   1},
            {INF, INF, INF, 0}
        };
        vector<vector<int>> path(V, vector<int>(V));
        
        floyd(V, graph, path);
        printDistanceMatrix(graph, path);
        
        cout << "\n从顶点0到顶点3的路径: ";
        int distance = printPath(graph, path, 0, 3);
        cout << "\n距离: " << distance << endl;
    }

    cout << "\n=== 测试用例2: 包含负权边 ===" << endl;
    {
        const int V = 3;
        vector<vector<int>> graph = {
            {0,   -1, 3},
            {2,   0, INF},
            {INF, 4,   0}
        };
        vector<vector<int>> path(V, vector<int>(V));
        
        floyd(V, graph, path);
        printDistanceMatrix(graph, path);
        
        cout << "\n从顶点0到顶点2的路径: ";
        int distance = printPath(graph, path, 0, 2);
        cout << "\n距离: " << distance << endl;
    }

    cout << "\n=== 测试用例3: 不连通图 ===" << endl;
    {
        const int V = 4;
        vector<vector<int>> graph = {
            {0, INF, INF, INF},
            {INF, 0, INF, INF},
            {INF, INF, 0,   1},
            {INF, INF, INF, 0}
        };
        vector<vector<int>> path(V, vector<int>(V));
        
        floyd(V, graph, path);
        printDistanceMatrix(graph, path);
    }

    cout << "\n=== 测试用例4: 较大规模图 ===" << endl;
    {
        const int V = 5;
        vector<vector<int>> graph = {
            {0,   3,   8, INF, -4},
            {INF, 0, INF,   1,  7},
            {INF, 4,   0, INF, INF},
            {2, INF,  -5,   0, INF},
            {INF, INF, INF,  6,  0}
        };
        vector<vector<int>> path(V, vector<int>(V));
        
        floyd(V, graph, path);
        printDistanceMatrix(graph, path);
    }

    return 0;
}