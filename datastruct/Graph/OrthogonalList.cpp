/**
 * 图的十字链表实现
 * 功能：实现有向图的十字链表存储及DFS/BFS遍历
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

// 弧结点
typedef struct ArcBox {
    int tailvex, headvex;    // 弧尾和弧头顶点位置
    struct ArcBox *hlink;    // 指向弧头相同的下一条弧
    struct ArcBox *tlink;    // 指向弧尾相同的下一条弧
    int weight;              // 权值
} ArcBox;

// 顶点结点
typedef struct VexNode {
    VertextType data;        // 顶点信息
    ArcBox *firstin;         // 指向第一条入弧
    ArcBox *firstout;        // 指向第一条出弧
} VexNode;

// 十字链表结构体
typedef struct {
    VexNode xlist[MaxVertexNum]; // 顶点表
    int vexnum, arcnum;      // 顶点数和弧数
} OLGraph;

// 创建十字链表图
void CreateOLGraph(OLGraph &G) {
    cout << "输入顶点数和弧数:";
    cin >> G.vexnum >> G.arcnum;
    
    // 输入顶点信息
    cout << "输入顶点信息:";
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.xlist[i].data;
        G.xlist[i].firstin = nullptr;
        G.xlist[i].firstout = nullptr;
    }
    
    // 输入弧信息
    cout << "输入弧信息(格式：弧尾 弧头 权值):" << endl;
    for (int k = 0; k < G.arcnum; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        
        // 创建弧结点
        ArcBox *p = new ArcBox;
        p->tailvex = i;
        p->headvex = j;
        p->weight = w;
        
        // 链接到弧尾相同的链表
        p->tlink = G.xlist[i].firstout;
        G.xlist[i].firstout = p;
        
        // 链接到弧头相同的链表
        p->hlink = G.xlist[j].firstin;
        G.xlist[j].firstin = p;
    }
}

// 访问顶点
void visit(OLGraph G, int v) {
    cout << G.xlist[v].data << " ";
}

// 深度优先搜索(DFS)
void DFS(OLGraph G, int v) {
    visit(G, v);
    visited[v] = true;
    // 沿出边遍历
    ArcBox *p = G.xlist[v].firstout;
    while (p != nullptr) {
        if (!visited[p->headvex]) {
            DFS(G, p->headvex);
        }
        p = p->tlink;
    }
}

// 广度优先搜索(BFS)
void BFS(OLGraph G, int v) {
    queue<int> Q;
    visit(G, v);
    visited[v] = true;
    Q.push(v);
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ArcBox *p = G.xlist[u].firstout;
        while (p != nullptr) {
        if (!visited[p->headvex]) {
                visit(G, p->headvex);
                visited[p->headvex] = true;
                Q.push(p->headvex);
            }
            p = p->tlink;
        }
    }
}

// 测试用例
int main() {
    OLGraph G;
    CreateOLGraph(G);
    
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
