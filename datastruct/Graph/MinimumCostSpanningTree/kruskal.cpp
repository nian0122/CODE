/**
 * Kruskal最小生成树算法实现
 * 功能：使用邻接矩阵实现Kruskal算法求解最小生成树
 * 适用于无向连通带权图
 * 时间复杂度：
 *   - 边排序：O(E log E)
 *   - 并查集操作：O(E α(V))
 * 空间复杂度：O(V + E)
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX_NUM 5  // 图中最大顶点数量
#define MAX_EDGE_NUM 10   // 图中最大边数量
typedef int VertexType;   // 顶点数据类型
typedef int EdgeType;     // 边权值类型

// 边结构体
typedef struct {
    int u, v;    // 边的两个顶点
    EdgeType w;  // 边的权值
} Edge;

// 邻接矩阵结构体
typedef struct {
    VertexType vex[MAX_VERTEX_NUM];           // 顶点表
    EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum, arcnum;                       // 顶点数和边数
} MGraph;

// 并查集父节点数组
int parent[MAX_VERTEX_NUM];

/**
 * 查找根节点（路径压缩）
 * @param x 要查找的节点
 * @return 根节点
 * 时间复杂度: O(α(V))
 */
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

/**
 * 合并两个集合
 * @param x 第一个节点
 * @param y 第二个节点
 * @return 合并成功返回1，已在同一集合返回0
 * 时间复杂度: O(α(V))
 */
int union_set(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y) return 0;
    parent[root_x] = root_y;
    return 1;
}

/**
 * 边比较函数（用于qsort）
 * @param a 第一条边
 * @param b 第二条边
 * @return 比较结果
 */
int edge_compare(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

// 最小生成树结果结构体
typedef struct {
    Edge edges[MAX_VERTEX_NUM - 1]; // 最小生成树的边
    int count;                      // 选中的边数
} MSTResult;

/**
 * Kruskal算法实现
 * @param graph 图结构
 * @param edges 边集数组
 * @param edge_count 边数量
 * @param result 存储最小生成树结果
 * @return 成功返回1，失败返回0
 * 时间复杂度: O(E log E + E α(V))
 */
int kruskal_mst(MGraph graph, Edge edges[], int edge_count, MSTResult *result) {
    // 初始化并查集
    for (int i = 0; i < graph.vexnum; i++) {
        parent[i] = i;
    }

    // 对边按权值排序
    qsort(edges, edge_count, sizeof(Edge), edge_compare);

    result->count = 0;

    // 遍历所有边
    for (int i = 0; i < edge_count && result->count < graph.vexnum - 1; i++) {
        if (union_set(edges[i].u, edges[i].v)) {
            result->edges[result->count] = edges[i];
            result->count++;
        }
    }

    return result->count == graph.vexnum - 1;
}

/**
 * 测试Kruskal算法
 * 时间复杂度: O(1)
 */
int main() {
    MGraph graph;
    graph.vexnum = 5;
    graph.arcnum = 7;

    /* 初始化测试图例:
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // 初始化邻接矩阵
    for (int i = 0; i < graph.vexnum; i++) {
        for (int j = 0; j < graph.vexnum; j++) {
            graph.edge[i][j] = edges[i][j];
        }
    }

    // 构建边集数组
    Edge edge_list[MAX_EDGE_NUM];
    int edge_count = 0;
    for (int i = 0; i < graph.vexnum; i++) {
        for (int j = i + 1; j < graph.vexnum; j++) {
            if (graph.edge[i][j] != 0) {
                edge_list[edge_count].u = i;
                edge_list[edge_count].v = j;
                edge_list[edge_count].w = graph.edge[i][j];
                edge_count++;
            }
        }
    }

    MSTResult result;
    if (kruskal_mst(graph, edge_list, edge_count, &result)) {
        printf("Kruskal算法生成的最小生成树:\n");
        printf("边 \t权重\n");
        for (int i = 0; i < result.count; i++) {
            printf("%d - %d \t%d \n", 
                   result.edges[i].u, 
                   result.edges[i].v, 
                   result.edges[i].w);
        }
    } else {
        printf("无法生成最小生成树\n");
    }

    return 0;
}
