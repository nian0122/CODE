#include <iostream>

// 图中最大顶点数
const int maxSize = 100;

/**
 * 弧节点结构体
 * adjV: 弧指向的顶点位置
 * next: 指向下一条弧的指针
 */
typedef struct ArcNode {
    int adjV;
    struct ArcNode *next;
} ArcNode;

/**
 * 顶点节点结构体
 * count: 顶点入度
 * first: 指向第一条依附该顶点的弧
 */
typedef struct VNode {
    int count;
    ArcNode *first;
} VNode;

/**
 * 图的邻接表结构体
 * adjList: 顶点数组
 * n: 图中顶点数
 */
typedef struct AGraph {
    VNode adjList[maxSize];
    int n;
} AGraph;

/**
 * 拓扑排序算法
 * @param G 图的邻接表表示
 * @return 成功返回1，失败返回0
 * 时间复杂度: O(V+E)
 */
int TopSort(AGraph *G) {
    int i, j, n = 0;
    int stack[maxSize], top = -1;
    ArcNode *p;

    for (i = 0; i < G->n; ++i) {
        if (G->adjList[i].count == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        i = stack[top--];
        ++n;
        std::cout << i << " ";
        p = G->adjList[i].first;

        while (p != NULL) {
            j = p->adjV;
            --(G->adjList[j].count);
            if (G->adjList[j].count == 0) {
                stack[++top] = j;
            }
            p = p->next;
        }
    }

    if (n == G->n) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 测试拓扑排序
 * 构建一个示例图并测试拓扑排序功能
 * 示例图结构:
 *   0 → 1 → 3 → 4
 *   ↓   ↑
 *   2 → 3
 */
int main() {
    AGraph G;
    G.n = 5; // 设置图中顶点数为5
    
    // 初始化所有顶点
    for (int i = 0; i < G.n; ++i) {
        G.adjList[i].count = 0;    // 初始化入度为0
        G.adjList[i].first = NULL; // 初始化边链表为空
    }

    // 添加边构建图结构
    ArcNode *p;
    
    // 添加边 0→1
    p = new ArcNode;
    p->adjV = 1;                      // 指向顶点1
    p->next = G.adjList[0].first;      // 插入到顶点0的边链表头部
    G.adjList[0].first = p;
    G.adjList[1].count++;              // 顶点1入度加1
    
    // 添加边 0→2
    p = new ArcNode;
    p->adjV = 2;                      // 指向顶点2
    p->next = G.adjList[0].first;      // 插入到顶点0的边链表头部
    G.adjList[0].first = p;
    G.adjList[2].count++;              // 顶点2入度加1
    
    // 添加边 1→3
    p = new ArcNode;
    p->adjV = 3;                      // 指向顶点3
    p->next = G.adjList[1].first;      // 插入到顶点1的边链表头部
    G.adjList[1].first = p;
    G.adjList[3].count++;              // 顶点3入度加1
    
    // 添加边 2→3
    p = new ArcNode;
    p->adjV = 3;                      // 指向顶点3
    p->next = G.adjList[2].first;      // 插入到顶点2的边链表头部
    G.adjList[2].first = p;
    G.adjList[3].count++;              // 顶点3入度加1
    
    // 添加边 3→4
    p = new ArcNode;
    p->adjV = 4;                      // 指向顶点4
    p->next = G.adjList[3].first;      // 插入到顶点3的边链表头部
    G.adjList[3].first = p;
    G.adjList[4].count++;              // 顶点4入度加1

    // 执行拓扑排序并输出结果
    std::cout << "拓扑排序结果: ";
    if (TopSort(&G)) {
        std::cout << "\n拓扑排序成功" << std::endl;
    } else {
        std::cout << "\n图中存在环" << std::endl;
    }

    return 0;
}