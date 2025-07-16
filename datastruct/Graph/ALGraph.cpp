/**
 * 图的邻接表实现
 * 适用于稀疏图
 * 邻接表有向图 邻接表+逆邻接表无向图
 * 功能：实现图的邻接表和逆邻接表存储，支持顶点和边的增删改操作
 * 时间复杂度：
 *   - 创建：O(n+e)
 *   - 添加顶点：O(1)
 *   - 删除顶点：O(n+e)
 *   - 添加边：O(1)
 *   - 删除边：O(d), d为顶点出度
 *   - DFS/BFS：O(n+e)
 * 空间复杂度：O(n+e)
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MaxVertexNum 100
typedef char VertextType;
bool visited[MaxVertexNum];

// 边结点
typedef struct ArcNode {
    int adjvex;              // 该边指向的顶点位置
    struct ArcNode *nextarc; // 指向下一条边的指针
    int weight;              // 边的权值
} ArcNode;

// 顶点结点
typedef struct VNode {
    VertextType data;        // 顶点信息
    ArcNode *firstarc;       // 指向第一条出边(邻接表)
    ArcNode *firstin;        // 指向第一条入边(逆邻接表)
} VNode, AdjList[MaxVertexNum];

// 邻接表结构体
typedef struct {
    AdjList vertices;        // 邻接表
    int vexnum, arcnum;      // 顶点数和边数
} ALGraph;

/**
 * 添加顶点
 * @param G 图引用
 * @param data 顶点数据
 * @return 添加成功返回顶点位置，失败返回-1
 * 时间复杂度: O(1)
 */
int AddVertex(ALGraph &G, VertextType data) {
    if (G.vexnum >= MaxVertexNum) return -1;
    G.vertices[G.vexnum].data = data;
    G.vertices[G.vexnum].firstarc = nullptr;
    G.vertices[G.vexnum].firstin = nullptr;
    return G.vexnum++;
}

/**
 * 删除顶点
 * @param G 图引用
 * @param v 顶点位置
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(n+e)
 */
bool RemoveVertex(ALGraph &G, int v) {
    if (v < 0 || v >= G.vexnum) return false;
    
    // 删除所有出边
    ArcNode *p = G.vertices[v].firstarc;
    while (p != nullptr) {
        ArcNode *temp = p;
        p = p->nextarc;
        // 在逆邻接表中删除对应边
        RemoveEdge(G, p->adjvex, v);
        delete temp;
        G.arcnum--;
    }
    
    // 删除所有入边
    p = G.vertices[v].firstin;
    while (p != nullptr) {
        ArcNode *temp = p;
        p = p->nextarc;
        // 在邻接表中删除对应边
        RemoveEdge(G, p->adjvex, v);
        delete temp;
        G.arcnum--;
    }
    
    // 移动最后一个顶点到当前位置
    if (v != G.vexnum - 1) {
        G.vertices[v] = G.vertices[G.vexnum - 1];
        // 更新所有指向该顶点的边
        UpdateVertexRefs(G, G.vexnum - 1, v);
    }
    
    G.vexnum--;
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
bool AddEdge(ALGraph &G, int v1, int v2, int w) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum) 
        return false;
    
    // 添加v1->v2的边(邻接表)
    ArcNode *p = new ArcNode;
    p->adjvex = v2;
    p->weight = w;
    p->nextarc = G.vertices[v1].firstarc;
    G.vertices[v1].firstarc = p;
    
    // 添加v2<-v1的边(逆邻接表)
    p = new ArcNode;
    p->adjvex = v1;
    p->weight = w;
    p->nextarc = G.vertices[v2].firstin;
    G.vertices[v2].firstin = p;
    
    G.arcnum++;
    return true;
}

/**
 * 删除边
 * @param G 图引用
 * @param v1 起点
 * @param v2 终点
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(d), d为顶点出度
 */
bool RemoveEdge(ALGraph &G, int v1, int v2) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum) 
        return false;
    
    // 从邻接表中删除v1->v2的边
    ArcNode *p = G.vertices[v1].firstarc;
    ArcNode *pre = nullptr;
    while (p != nullptr && p->adjvex != v2) {
        pre = p;
        p = p->nextarc;
    }
    if (p != nullptr) {
        if (pre == nullptr) 
            G.vertices[v1].firstarc = p->nextarc;
        else 
            pre->nextarc = p->nextarc;
        delete p;
    }
    
    // 从逆邻接表中删除v2<-v1的边
    p = G.vertices[v2].firstin;
    pre = nullptr;
    while (p != nullptr && p->adjvex != v1) {
        pre = p;
        p = p->nextarc;
    }
    if (p != nullptr) {
        if (pre == nullptr) 
            G.vertices[v2].firstin = p->nextarc;
        else 
            pre->nextarc = p->nextarc;
        delete p;
        G.arcnum--;
        return true;
    }
    return false;
}


/**
 * 更新顶点引用(内部使用)
 * @param G 图引用
 * @param old_v 原顶点位置
 * @param new_v 新顶点位置
 * 时间复杂度: O(n+e)
 */
void UpdateVertexRefs(ALGraph &G, int old_v, int new_v) {
    // 更新邻接表中的引用
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != nullptr) {
            if (p->adjvex == old_v) 
                p->adjvex = new_v;
            p = p->nextarc;
        }
    }
    
    // 更新逆邻接表中的引用
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstin;
        while (p != nullptr) {
            if (p->adjvex == old_v) 
                p->adjvex = new_v;
            p = p->nextarc;
        }
    }
}

