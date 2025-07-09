/**
 * 图的邻接多重表实现
 * 功能：实现无向图的邻接多重表存储及DFS/BFS遍历
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
typedef struct EBox {
    int ivex, jvex;         // 该边依附的两个顶点位置
    struct EBox *ilink;     // 指向依附顶点ivex的下一条边
    struct EBox *jlink;     // 指向依附顶点jvex的下一条边
    int weight;             // 权值
} EBox;

// 顶点结点
typedef struct VexBox {
    VertextType data;       // 顶点信息
    EBox *firstedge;        // 指向第一条依附该顶点的边
} VexBox;

// 邻接多重表结构体
typedef struct {
    VexBox adjmulist[MaxVertexNum]; // 顶点表
    int vexnum, edgenum;    // 顶点数和边数
} AMLGraph;

// 创建邻接多重表图
void CreateAMLGraph(AMLGraph &G) {
    cout << "输入顶点数和边数:";
    cin >> G.vexnum >> G.edgenum;
    
    // 输入顶点信息
    cout << "输入顶点信息:";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.adjmulist[i].data;
        G.adjmulist[i].firstedge = nullptr;
    }
    
    // 输入边信息
    cout << "输入边信息(格式：顶点1 顶点2 权值):" << endl;
    for (int k = 0; k < G.edgenum; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        
        // 创建边结点
        EBox *p = new EBox;
        p->ivex = i;
        p->jvex = j;
        p->weight = w;
        
        // 链接到顶点i的边链表
        p->ilink = G.adjmulist[i].firstedge;
        G.adjmulist[i].firstedge = p;
        
        // 链接到顶点j的边链表
        p->jlink = G.adjmulist[j].firstedge;
        G.adjmulist[j].firstedge = p;
    }
}

// 访问顶点
void visit(AMLGraph G, int v) {
    cout << G.adjmulist[v].data << " ";
}

// 深度优先搜索(DFS)
void DFS(AMLGraph G, int v) {
    visit(G, v);
    visited[v] = true;
    EBox *p = G.adjmulist[v].firstedge;
    while (p != nullptr) {
        int w = (p->ivex == v) ? p->jvex : p->ivex;
        if (!visited[w]) {
            DFS(G, w);
        }
        p = (p->ivex == v) ? p->ilink : p->jlink;
    }
}

// 广度优先搜索(BFS)
void BFS(AMLGraph G, int v) {
    queue<int> Q;
    visit(G, v);
    visited[v] = true;
    Q.push(v);
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        EBox *p = G.adjmulist[u].firstedge;
        while (p != nullptr) {
            int w = (p->ivex == u) ? p->jvex : p->ivex;
            if (!visited[w]) {
                visit(G, w);
                visited[w] = true;
                Q.push(w);
            }
            p = (p->ivex == u) ? p->ilink : p->jlink;
        }
    }
}

// 测试用例
int main() {
    AMLGraph G;
    CreateAMLGraph(G);
    
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
