/**
 * Dijkstra 最短路径算法实现
 * 使用优先队列优化，计算从源点到所有其他顶点的最短路径
 * 
 * 时间复杂度: O((V+E)logV)
 * 空间复杂度: O(V+E)
 */

#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

// 定义边的结构体
struct Edge {
    int to;     // 目标顶点
    int weight; // 边权重
};

// 定义优先队列中使用的节点
struct QueueNode {
    int vertex;
    int distance;
    
    // 重载 < 运算符用于优先队列
    bool operator<(const QueueNode& other) const {
        return distance > other.distance; // 最小堆
    }
};

/**
 * Dijkstra 算法实现
 * @param graph 图的邻接表表示
 * @param start 源点
 * @return 包含从源点到所有顶点最短距离的数组
 */
vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // 初始化所有距离为无穷大
    vector<bool> visited(n, false); // 标记已访问的顶点
    
    priority_queue<QueueNode> pq;
    
    dist[start] = 0;
    pq.push({start, 0});
    
    while (!pq.empty()) {
        QueueNode current = pq.top();
        pq.pop();
        int u = current.vertex;
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // 遍历所有邻接边
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            
            // 松弛操作
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
    
    return dist;
}

/**
 * 测试 Dijkstra 算法
 */
int main() {
    // 示例图
    // 顶点数
    const int V = 5;
    // 创建图的邻接表
    vector<vector<Edge>> graph(V);
    
    // 添加边
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});
    
    // 从顶点 0 开始计算最短路径
    vector<int> distances = dijkstra(graph, 0);
    
    // 输出结果
    cout << "顶点\t距离" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << distances[i] << endl;
    }
    
    return 0;
}
