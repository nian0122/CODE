/**
 * 图的邻接表实现
 * 功能：实现图的邻接表存储及DFS/BFS遍历
 * 时间复杂度：
 *   - 创建：O(n+e)
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
    ArcNode *firstarc;       // 指向第一条依附该顶点的边
} VNode, AdjList[MaxVertexNum];

// 邻接表结构体
typedef struct {
    AdjList vertices;        // 邻接表
    int vexnum, arcnum;      // 顶点数和边数
} ALGraph;

// 创建邻接表图
void CreateALGraph(ALGraph &G) {
    cout << "输入顶点数和边数:";
    cin >> G.vexnum >> G.arcnum;
    
    // 输入顶点信息
    cout << "输入顶点信息:";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }
    
    // 输入边信息
    cout << "输入边信息(格式：顶点1 顶点2 权值):" << endl;
    for (int k = 0; k < G.arcnum; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        
        // 添加i->j的边
        ArcNode *p = new ArcNode;
        p->adjvex = j;
        p->weight = w;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
        
        // 无向图，添加j->i的边
        p = new ArcNode;
        p->adjvex = i;
        p->weight = w;
        p->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p;
    }
}

// 访问顶点
void visit(ALGraph G, int v) {
    cout << G.vertices[v].data << " ";
}

// 深度优先搜索(DFS)
void DFS(ALGraph G, int v) {
    visit(G, v);
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while (p != nullptr) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

// 广度优先搜索(BFS)
void BFS(ALGraph G, int v) {
    queue<int> Q;
    visit(G, v);
    visited[v] = true;
    Q.push(v);
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ArcNode *p = G.vertices[u].firstarc;
        while (p != nullptr) {
            if (!visited[p->adjvex]) {
                visit(G, p->adjvex);
                visited[p->adjvex] = true;
                Q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

// 测试用例
int main() {
    ALGraph G;
    CreateALGraph(G);
    
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
