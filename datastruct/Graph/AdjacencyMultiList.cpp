/**
 * 图的邻接多重表实现
 * 功能：实现无向图的邻接多重表存储
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
typedef int EdgeType;
bool visited[MaxVertexNum];

// 边节点结构
typedef struct EdgeNode {
    int ivex, jvex;         // 该边依附的两个顶点位置
    EdgeType weight;        // 边权重
    struct EdgeNode *ilink; // 指向下一条依附于顶点ivex的边
    struct EdgeNode *jlink; // 指向下一条依附于顶点jvex的边
} EdgeNode;

// 顶点节点结构
typedef struct VertexNode {
    VertextType data;       // 顶点数据
    EdgeNode *first_edge;   // 指向第一条依附该顶点的边
} VertexNode;

// 邻接多重表图结构
typedef struct {
    VertexNode adj_multi_list[MaxVertexNum]; // 顶点数组
    int vertex_num;                          // 当前顶点数
    int edge_num;                            // 当前边数
} AMLGraph;

/**
 * 初始化邻接多重表
 * @param G 图指针
 */
void init_aml_graph(AMLGraph *G) {
    G->vertex_num = 0;
    G->edge_num = 0;
    for (int i = 0; i < MaxVertexNum; i++) {
        G->adj_multi_list[i].first_edge = nullptr;
    }
}

/**
 * 添加顶点
 * @param G 图指针
 * @param v 顶点数据
 * @return 顶点位置索引，-1表示失败
 */
int add_vertex(AMLGraph *G, VertextType v) {
    if (G->vertex_num >= MaxVertexNum) {
        return -1;
    }
    G->adj_multi_list[G->vertex_num].data = v;
    G->adj_multi_list[G->vertex_num].first_edge = nullptr;
    return G->vertex_num++;
}

/**
 * 添加边
 * @param G 图指针
 * @param v1 顶点1索引
 * @param v2 顶点2索引
 * @param weight 边权重
 * @return 是否成功
 */
bool add_edge(AMLGraph *G, int v1, int v2, EdgeType weight) {
    if (v1 < 0 || v1 >= G->vertex_num || v2 < 0 || v2 >= G->vertex_num) {
        return false;
    }

    EdgeNode *edge = new EdgeNode;
    edge->ivex = v1;
    edge->jvex = v2;
    edge->weight = weight;
    
    // 将边插入到顶点v1的边链表中
    edge->ilink = G->adj_multi_list[v1].first_edge;
    G->adj_multi_list[v1].first_edge = edge;
    
    // 将边插入到顶点v2的边链表中
    edge->jlink = G->adj_multi_list[v2].first_edge;
    G->adj_multi_list[v2].first_edge = edge;
    
    G->edge_num++;
    return true;
}

/**
 * 删除边
 * @param G 图指针
 * @param v1 顶点1索引
 * @param v2 顶点2索引
 * @return 是否成功
 */
bool remove_edge(AMLGraph *G, int v1, int v2) {
    if (v1 < 0 || v1 >= G->vertex_num || v2 < 0 || v2 >= G->vertex_num) {
        return false;
    }

    // 从顶点v1的边链表中删除
    EdgeNode *prev = nullptr;
    EdgeNode *current = G->adj_multi_list[v1].first_edge;
    while (current != nullptr) {
        if ((current->ivex == v1 && current->jvex == v2) || 
            (current->ivex == v2 && current->jvex == v1)) {
            if (prev == nullptr) {
                G->adj_multi_list[v1].first_edge = current->ilink;
            } else {
                prev->ilink = current->ilink;
            }
            break;
        }
        prev = current;
        current = current->ilink;
    }

    // 从顶点v2的边链表中删除
    prev = nullptr;
    current = G->adj_multi_list[v2].first_edge;
    while (current != nullptr) {
        if ((current->ivex == v1 && current->jvex == v2) || 
            (current->ivex == v2 && current->jvex == v1)) {
            if (prev == nullptr) {
                G->adj_multi_list[v2].first_edge = current->jlink;
            } else {
                prev->jlink = current->jlink;
            }
            delete current;
            G->edge_num--;
            return true;
        }
        prev = current;
        current = current->jlink;
    }

    return false;
}

/**
 * 删除顶点
 * @param G 图指针
 * @param v 顶点索引
 * @return 是否成功
 */
bool remove_vertex(AMLGraph *G, int v) {
    if (v < 0 || v >= G->vertex_num) {
        return false;
    }

    // 先删除所有与该顶点相关的边
    EdgeNode *edge = G->adj_multi_list[v].first_edge;
    while (edge != nullptr) {
        int other_v = (edge->ivex == v) ? edge->jvex : edge->ivex;
        remove_edge(G, v, other_v);
        edge = G->adj_multi_list[v].first_edge;
    }

    // 将最后一个顶点移动到被删除顶点的位置
    if (v != G->vertex_num - 1) {
        G->adj_multi_list[v] = G->adj_multi_list[G->vertex_num - 1];
        
        // 更新所有指向最后一个顶点的边
        edge = G->adj_multi_list[v].first_edge;
        while (edge != nullptr) {
            if (edge->ivex == G->vertex_num - 1) {
                edge->ivex = v;
            }
            if (edge->jvex == G->vertex_num - 1) {
                edge->jvex = v;
            }
            edge = (edge->ivex == v) ? edge->ilink : edge->jlink;
        }
    }

    G->vertex_num--;
    return true;
}

/**
 * 修改顶点数据
 * @param G 图指针
 * @param v 顶点索引
 * @param new_data 新数据
 * @return 是否成功
 */
bool modify_vertex(AMLGraph *G, int v, VertextType new_data) {
    if (v < 0 || v >= G->vertex_num) {
        return false;
    }
    G->adj_multi_list[v].data = new_data;
    return true;
}

/**
 * 修改边权重
 * @param G 图指针
 * @param v1 顶点1索引
 * @param v2 顶点2索引
 * @param new_weight 新权重
 * @return 是否成功
 */
bool modify_edge(AMLGraph *G, int v1, int v2, EdgeType new_weight) {
    if (v1 < 0 || v1 >= G->vertex_num || v2 < 0 || v2 >= G->vertex_num) {
        return false;
    }

    EdgeNode *edge = G->adj_multi_list[v1].first_edge;
    while (edge != nullptr) {
        if ((edge->ivex == v1 && edge->jvex == v2) || 
            (edge->ivex == v2 && edge->jvex == v1)) {
            edge->weight = new_weight;
            return true;
        }
        edge = edge->ilink;
    }

    return false;
}

int main() {
    AMLGraph G;
    init_aml_graph(&G);
    
    // 测试代码
    int v1 = add_vertex(&G, 'A');
    int v2 = add_vertex(&G, 'B');
    int v3 = add_vertex(&G, 'C');
    
    add_edge(&G, v1, v2, 1);
    add_edge(&G, v2, v3, 2);
    add_edge(&G, v1, v3, 3);
    
    modify_edge(&G, v1, v3, 5);
    remove_edge(&G, v2, v3);
    remove_vertex(&G, v2);
    
    return 0;
}

