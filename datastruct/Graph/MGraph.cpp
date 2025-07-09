/**
 * 图的邻接矩阵实现
 * 功能：实现图的邻接矩阵存储及DFS/BFS遍历
 * 时间复杂度：
 *   - 创建：O(n^2)
 *   - DFS/BFS：O(n^2)
 * 空间复杂度：O(n^2)
 */
#include <iostream>
#include <queue>
using namespace std;

#define MaxVertexNum 100
typedef char VertextType;
typedef int EdgeType;
bool visited[MaxVertexNum];

// 邻接矩阵结构体
typedef struct {
    VertextType vex[MaxVertexNum];        // 顶点表
    EdgeType edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
    int vexnum, arcnum;                   // 顶点数和边数
} MGraph;

// 创建邻接矩阵图
void CreateMGraph(MGraph &G) {
    cout << "输入顶点数和边数:";
    cin >> G.vexnum >> G.arcnum;
    
    // 输入顶点信息
    cout << "输入顶点信息:";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vex[i];
    }
    
    // 初始化邻接矩阵
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = 0;
        }
    }
    
    // 输入边信息
    cout << "输入边信息(格式：顶点1 顶点2 权值):" << endl;
    for (int k = 0; k < G.arcnum; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        G.edge[i][j] = w;
        G.edge[j][i] = w; // 无向图
    }
}

// 访问顶点
void visit(MGraph G, int v) {
    cout << G.vex[v] << " ";
}

// 深度优先搜索(DFS)
void DFS(MGraph G, int v) {
    visit(G, v);
    visited[v] = true;
    for (int w = 0; w < G.vexnum; w++) {
        if (G.edge[v][w] != 0 && !visited[w]) {
            DFS(G, w);
        }
    }
}

// 广度优先搜索(BFS)
void BFS(MGraph G, int v) {
    queue<int> Q;
    visit(G, v);
    visited[v] = true;
    Q.push(v);
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
    for (int w = 0; w < G.vexnum; w++) {
        if (G.edge[u][w] != 0 && !visited[w]) {
                visit(G, w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}


// 初始化复杂测试图(完全图)
void initComplexGraph(MGraph &G) {
    // 5个顶点的完全图
    G.vexnum = 5;
    G.arcnum = 10;
    
    // 顶点信息
    G.vex[0] = 'A';
    G.vex[1] = 'B';
    G.vex[2] = 'C';
    G.vex[3] = 'D';
    G.vex[4] = 'E';
    
    // 初始化邻接矩阵
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = (i == j) ? 0 : 1; // 完全图，除对角线外全为1
        }
    }
}

// 测试用例
int main() {
    MGraph G;
    initComplexGraph(G);

    
    // 初始化访问数组
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    cout << "DFS遍历结果:";
    DFS(G, 0);
    cout << endl;
    
    // 重置访问数组
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    cout << "BFS遍历结果:";
    BFS(G, 0);
    cout << endl;
    
    return 0;
}
