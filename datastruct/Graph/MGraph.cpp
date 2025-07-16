/**
 * 图的邻接矩阵实现
 * 功能：实现图的邻接矩阵存储，支持顶点和边的增删改操作
 * 适用于稠密图 有向图 无向图
 * 时间复杂度：
 *   - 创建：O(n^2)
 *   - 添加顶点：O(n)
 *   - 删除顶点：O(n^2)
 *   - 添加/删除/修改边：O(1)
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

/**
 * 添加顶点
 * @param G 图引用
 * @param data 顶点数据
 * @return 添加成功返回顶点位置，失败返回-1
 * 时间复杂度: O(n)
 */
int AddVertex(MGraph &G, VertextType data) {
    if (G.vexnum >= MaxVertexNum) return -1;
    G.vex[G.vexnum] = data;
    
    // 初始化新顶点的边
    for (int i = 0; i <= G.vexnum; i++) {
        G.edge[G.vexnum][i] = 0;
        G.edge[i][G.vexnum] = 0;
    }
    
    return G.vexnum++;
}

/**
 * 删除顶点
 * @param G 图引用
 * @param v 顶点位置
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(n^2)
 */
bool RemoveVertex(MGraph &G, int v) {
    if (v < 0 || v >= G.vexnum) return false;
    
    // 统计要删除的边数
    int edgeCount = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.edge[v][i] != 0) edgeCount++;
        if (G.edge[i][v] != 0 && i != v) edgeCount++;
    }
    
    // 移动顶点
    for (int i = v; i < G.vexnum - 1; i++) {
        G.vex[i] = G.vex[i + 1];
    }
    
    // 移动边
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = v; j < G.vexnum - 1; j++) {
            G.edge[i][j] = G.edge[i][j + 1];
        }
    }
    for (int i = v; i < G.vexnum - 1; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = G.edge[i + 1][j];
        }
    }
    
    G.vexnum--;
    G.arcnum -= edgeCount;
    return true;
}

/**
 * 添加边
 * @param G 图引用
 * @param v1 起点
 * @param v2 终点
 * @param w 权值
 * @return 添加成功返回true，失败返回false
 * 时间复杂度: O(1)
 */
bool AddEdge(MGraph &G, int v1, int v2, int w) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum)
        return false;
    
    if (G.edge[v1][v2] == 0) G.arcnum++;
    G.edge[v1][v2] = w;
    G.edge[v2][v1] = w; // 无向图
    return true;
}

/**
 * 删除边
 * @param G 图引用
 * @param v1 起点
 * @param v2 终点
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(1)
 */
bool RemoveEdge(MGraph &G, int v1, int v2) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum)
        return false;
    
    if (G.edge[v1][v2] != 0) G.arcnum--;
    G.edge[v1][v2] = 0;
    G.edge[v2][v1] = 0; // 无向图
    return true;
}

/**
 * 修改边权值
 * @param G 图引用
 * @param v1 起点
 * @param v2 终点
 * @param w 新权值
 * @return 修改成功返回true，失败返回false
 * 时间复杂度: O(1)
 */
bool UpdateEdge(MGraph &G, int v1, int v2, int w) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum)
        return false;
    
    G.edge[v1][v2] = w;
    G.edge[v2][v1] = w; // 无向图
    return true;
}

