/**
 * 图的十字链表实现
 * 功能：实现有向图的十字链表存储，支持顶点和边的增删改操作
 * 时间复杂度：
 *   - 创建：O(n+e)
 *   - 添加顶点：O(1)
 *   - 删除顶点：O(n+e)
 *   - 添加/删除边：O(d), d为顶点出度
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
    int tailvex, headvex;         // 弧尾和弧头顶点位置
    struct ArcNode *hlink, *tlink; // 指向相同弧头和弧尾的下一条边
    int weight;                   // 边的权值
} ArcNode;

// 顶点结点
typedef struct VexNode {
    VertextType data;             // 顶点信息
    ArcNode *firstin, *firstout;  // 指向第一条入边和出边
} VexNode, OrthogonalList[MaxVertexNum];

// 十字链表结构体
typedef struct {
    OrthogonalList vertices;      // 十字链表
    int vexnum, arcnum;           // 顶点数和边数
} OLGraph;

/**
 * 添加顶点
 * @param G 图引用
 * @param data 顶点数据
 * @return 添加成功返回顶点位置，失败返回-1
 * 时间复杂度: O(1)
 */
int AddVertex(OLGraph &G, VertextType data) {
    if (G.vexnum >= MaxVertexNum) return -1;
    G.vertices[G.vexnum].data = data;
    G.vertices[G.vexnum].firstin = nullptr;
    G.vertices[G.vexnum].firstout = nullptr;
    return G.vexnum++;
}

/**
 * 删除顶点
 * @param G 图引用
 * @param v 顶点位置
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(n+e)
 */
bool RemoveVertex(OLGraph &G, int v) {
    if (v < 0 || v >= G.vexnum) return false;
    
    // 删除所有出边
    ArcNode *p = G.vertices[v].firstout;
    while (p != nullptr) {
        ArcNode *temp = p;
        p = p->hlink;
        // 在入边链表中删除对应边
        RemoveEdge(G, v, temp->headvex);
        delete temp;
        G.arcnum--;
    }
    
    // 删除所有入边
    p = G.vertices[v].firstin;
    while (p != nullptr) {
        ArcNode *temp = p;
        p = p->tlink;
        // 在出边链表中删除对应边
        RemoveEdge(G, temp->tailvex, v);
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
bool AddEdge(OLGraph &G, int v1, int v2, int w) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum) 
        return false;
    
    // 创建新边结点
    ArcNode *p = new ArcNode;
    p->tailvex = v1;
    p->headvex = v2;
    p->weight = w;
    
    // 添加到出边链表
    p->hlink = G.vertices[v1].firstout;
    G.vertices[v1].firstout = p;
    
    // 添加入边链表
    p->tlink = G.vertices[v2].firstin;
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
bool RemoveEdge(OLGraph &G, int v1, int v2) {
    if (v1 < 0 || v1 >= G.vexnum || v2 < 0 || v2 >= G.vexnum) 
        return false;
    
    // 从出边链表中删除
    ArcNode *p = G.vertices[v1].firstout;
    ArcNode *pre = nullptr;
    while (p != nullptr && p->headvex != v2) {
        pre = p;
        p = p->hlink;
    }
    if (p != nullptr) {
        if (pre == nullptr) 
            G.vertices[v1].firstout = p->hlink;
        else 
            pre->hlink = p->hlink;
    }
    
    // 从入边链表中删除
    p = G.vertices[v2].firstin;
    pre = nullptr;
    while (p != nullptr && p->tailvex != v1) {
        pre = p;
        p = p->tlink;
    }
    if (p != nullptr) {
        if (pre == nullptr) 
            G.vertices[v2].firstin = p->tlink;
        else 
            pre->tlink = p->tlink;
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
void UpdateVertexRefs(OLGraph &G, int old_v, int new_v) {
    // 更新所有边的引用
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstout;
        while (p != nullptr) {
            if (p->tailvex == old_v) p->tailvex = new_v;
            if (p->headvex == old_v) p->headvex = new_v;
            p = p->hlink;
        }
    }
}

