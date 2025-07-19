#include <iostream>
#include <stack>
#include <climits>

// 图中最大顶点数，用于限制图的最大规模
// 可根据实际需求调整此值
const int maxSize = 100;

/**
 * 弧节点结构体
 * 表示图中的一条有向边/弧
 * adjV: 弧指向的顶点位置(数组下标)
 * weight: 弧的权重(活动持续时间)，在关键路径算法中表示活动持续时间
 * next: 指向下一条弧的指针，用于构建邻接表
 */
typedef struct ArcNode {
    int adjV;           // 目标顶点位置
    int weight;         // 弧的权重/活动持续时间
    struct ArcNode *next; // 下一条弧指针
} ArcNode;

/**
 * 顶点节点结构体
 * 表示图中的一个顶点
 * count: 顶点入度，用于拓扑排序
 * first: 指向第一条依附该顶点的弧，构成邻接表
 */
typedef struct VNode {
    int count;         // 顶点入度
    ArcNode *first;    // 邻接表头指针
} VNode;

/**
 * 图的邻接表结构体
 * 使用邻接表表示图结构
 * adjList: 顶点数组，每个元素是一个VNode
 * n: 图中当前顶点数，必须小于maxSize
 */
typedef struct AGraph {
    VNode adjList[maxSize]; // 顶点数组
    int n;                 // 顶点数量
} AGraph;

/**
 * 拓扑排序算法
 * 使用基于栈的Kahn算法实现拓扑排序
 * @param G 图的邻接表表示
 * @param topo 存储拓扑序列的数组，空间需由调用者分配
 * @return 成功返回1，失败返回0(图中存在环)
 * 时间复杂度: O(V+E) 空间复杂度: O(V)
 * 算法步骤:
 * 1. 初始化栈，将所有入度为0的顶点入栈
 * 2. 当栈不为空时，弹出顶点并加入拓扑序列
 * 3. 将该顶点的所有邻接顶点入度减1，若减为0则入栈
 * 4. 若拓扑序列包含所有顶点，则排序成功
 */
int TopSort(AGraph *G, int topo[]) {
    int i, j, n = 0;
    int stack[maxSize], top = -1;  // 使用数组模拟栈
    ArcNode *p;

    // 初始化：将所有入度为0的顶点入栈
    for (i = 0; i < G->n; ++i) {
        if (G->adjList[i].count == 0) {
            stack[++top] = i;  // 入栈
        }
    }

    // 拓扑排序主循环
    while (top != -1) {
        i = stack[top--];      // 出栈
        topo[n++] = i;         // 加入拓扑序列
        p = G->adjList[i].first;

        // 处理顶点i的所有邻接顶点
        while (p != NULL) {
            j = p->adjV;
            --(G->adjList[j].count);  // 邻接顶点入度减1
            if (G->adjList[j].count == 0) {
                stack[++top] = j;     // 若入度为0则入栈
            }
            p = p->next;
        }
    }

    // 检查是否所有顶点都加入了拓扑序列
    if (n == G->n) {
        return 1;  // 排序成功
    } else {
        return 0;  // 图中存在环，排序失败
    }
}

/**
 * 关键路径算法
 * 计算AOE网中的关键路径和关键活动
 * @param G 图的邻接表表示，必须是有向无环图(DAG)
 * @return 成功返回关键路径长度，失败返回-1(图中存在环)
 * 时间复杂度: O(V+E) 空间复杂度: O(V)
 * 算法步骤:
 * 1. 拓扑排序检查图中是否有环
 * 2. 按拓扑序计算各顶点的最早开始时间(ve)
 * 3. 按逆拓扑序计算各顶点的最晚开始时间(vl)
 * 4. 计算各活动的最早开始时间(ee)和最晚开始时间(el)
 * 5. 找出ee==el的活动即为关键活动，构成关键路径
 */
int CriticalPath(AGraph *G) {
    int i, j, k;
    ArcNode *p;
    int ve[maxSize] = {0};  // 顶点最早开始时间数组
    int vl[maxSize];         // 顶点最晚开始时间数组
    int topo[maxSize];       // 存储拓扑序列
    
    // 步骤1: 拓扑排序检查是否有环
    if (!TopSort(G, topo)) {
        std::cout << "图中存在环，无法计算关键路径" << std::endl;
        return -1;
    }

    // 步骤2: 计算ve数组(顶点最早开始时间)
    // 按拓扑序处理每个顶点
    for (i = 0; i < G->n; ++i) {
        j = topo[i];  // 当前顶点
        p = G->adjList[j].first;
        
        // 处理当前顶点的所有邻接顶点
        while (p != NULL) {
            k = p->adjV;
            // 更新邻接顶点的最早开始时间
            if (ve[j] + p->weight > ve[k]) {
                ve[k] = ve[j] + p->weight;
            }
            p = p->next;
        }
    }

    // 步骤3: 初始化vl数组(顶点最晚开始时间)
    // 所有顶点初始化为ve的最大值(最后一个顶点的ve值)
    for (i = 0; i < G->n; ++i) {
        vl[i] = ve[G->n - 1];
    }

    // 步骤4: 计算vl数组(顶点最晚开始时间)
    // 按逆拓扑序处理每个顶点
    for (i = G->n - 2; i >= 0; --i) {
        j = topo[i];  // 当前顶点
        p = G->adjList[j].first;
        
        // 处理当前顶点的所有邻接顶点
        while (p != NULL) {
            k = p->adjV;
            // 更新当前顶点的最晚开始时间
            if (vl[k] - p->weight < vl[j]) {
                vl[j] = vl[k] - p->weight;
            }
            p = p->next;
        }
    }

    // 步骤5: 输出关键路径
    std::cout << "关键路径: ";
    for (i = 0; i < G->n; ++i) {
        p = G->adjList[i].first;
        while (p != NULL) {
            j = p->adjV;
            int ee = ve[i];              // 活动最早开始时间
            int el = vl[j] - p->weight;  // 活动最晚开始时间
            // 关键活动条件: 最早开始时间 == 最晚开始时间
            if (ee == el) {
                std::cout << i << "->" << j << " ";
            }
            p = p->next;
        }
    }
    std::cout << std::endl;

    // 返回关键路径长度(最后一个顶点的最早开始时间)
    return ve[G->n - 1];
}

/**
 * 测试关键路径算法
 * 构建一个示例图并测试关键路径功能
 * 示例图结构(AOE网):
 *   0 →(6)→ 1 →(1)→ 3 →(5)→ 4
 *   ↓(4)    ↑(1)
 *   2 →(2)→ 3
 * 预期关键路径: 0→1→3→4，长度为12
 * 注意: 此测试用例未释放动态分配的内存，实际应用中应添加内存释放代码
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
    
    // 添加边 0→1 (权重6)
    p = new ArcNode;
    p->adjV = 1;
    p->weight = 6;
    p->next = G.adjList[0].first;
    G.adjList[0].first = p;
    G.adjList[1].count++;
    
    // 添加边 0→2 (权重4)
    p = new ArcNode;
    p->adjV = 2;
    p->weight = 4;
    p->next = G.adjList[0].first;
    G.adjList[0].first = p;
    G.adjList[2].count++;
    
    // 添加边 1→3 (权重1)
    p = new ArcNode;
    p->adjV = 3;
    p->weight = 1;
    p->next = G.adjList[1].first;
    G.adjList[1].first = p;
    G.adjList[3].count++;
    
    // 添加边 2→3 (权重2)
    p = new ArcNode;
    p->adjV = 3;
    p->weight = 2;
    p->next = G.adjList[2].first;
    G.adjList[2].first = p;
    G.adjList[3].count++;
    
    // 添加边 3→4 (权重5)
    p = new ArcNode;
    p->adjV = 4;
    p->weight = 5;
    p->next = G.adjList[3].first;
    G.adjList[3].first = p;
    G.adjList[4].count++;

    // 执行关键路径算法并输出结果
    int length = CriticalPath(&G);
    if (length != -1) {
        std::cout << "关键路径长度: " << length << std::endl;
    }

    // 注意: 实际应用中应在此处释放动态分配的ArcNode内存
    return 0;
}