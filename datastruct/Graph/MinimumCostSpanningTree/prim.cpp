/**
 * Prim最小生成树算法实现
 * 功能：使用邻接矩阵实现Prim算法求解最小生成树
 * 适用于无向连通带权图
 * 时间复杂度：
 *   - 邻接矩阵实现：O(V^2)
 *   - 邻接表+二叉堆实现：O(E log V)
 * 空间复杂度：O(V^2)
 */
#include <stdio.h>
#include <limits.h>

#define MAX_VERTEX_NUM 5  // 图中最大顶点数量
typedef int VertexType;   // 顶点数据类型
typedef int EdgeType;     // 边权值类型

// 邻接矩阵结构体
typedef struct {
    VertexType vex[MAX_VERTEX_NUM];           // 顶点表
    EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum;                                // 顶点数
} MGraph;

/**
 * 找到最小键值的顶点索引
 * @param key 键值数组
 * @param mst_set 顶点是否在MST中的标记数组
 * @param vertex_num 顶点数量
 * @return 最小键值顶点的索引
 * 时间复杂度: O(V)
 */
int find_min_key(EdgeType key[], bool mst_set[], int vertex_num) {
    EdgeType min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < vertex_num; v++) {
        if (mst_set[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

/**
 * 打印最小生成树
 * @param parent 父节点数组
 * @param graph 图结构
 * 时间复杂度: O(V)
 */
void print_mst(int parent[], MGraph graph) {
    printf("边 \t权重\n");
    for (int i = 1; i < graph.vexnum; i++) {
        printf("%d - %d \t%d \n", parent[i], i, 
               graph.edge[i][parent[i]]);
    }
}

/**
 * Prim算法实现
 * @param graph 图结构
 * 时间复杂度: O(V^2)
 */
void prim_mst(MGraph graph) {
    int parent[MAX_VERTEX_NUM];   // 存储最小生成树
    EdgeType key[MAX_VERTEX_NUM];  // 存储键值
    bool mst_set[MAX_VERTEX_NUM];  // 顶点是否包含在MST中

    // 初始化所有键值为无穷大
    for (int i = 0; i < graph.vexnum; i++) {
        key[i] = INT_MAX;
        mst_set[i] = false;
    }

    // 从第一个顶点开始
    key[0] = 0;     
    parent[0] = -1; // 第一个节点总是根节点

    // MST将有V个顶点
    for (int count = 0; count < graph.vexnum - 1; count++) {
        // 选取最小键值顶点
        int u = find_min_key(key, mst_set, graph.vexnum);
        mst_set[u] = true;

        // 更新相邻顶点的键值
        for (int v = 0; v < graph.vexnum; v++) {
            if (graph.edge[u][v] && mst_set[v] == false && 
                graph.edge[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph.edge[u][v];
            }
        }
    }

    // 打印构造的最小生成树
    print_mst(parent, graph);
}

/**
 * 测试Prim算法
 * 时间复杂度: O(1)
 */
int main() {
    MGraph graph;
    graph.vexnum = 5;

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

    printf("Prim算法生成的最小生成树:\n");
    prim_mst(graph);

    return 0;
}
