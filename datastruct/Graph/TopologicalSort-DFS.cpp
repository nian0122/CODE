/**
 * 基于DFS的拓扑排序实现
 * 时间复杂度: O(V+E)
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 图节点结构
struct graph_node {
    int id;
    vector<int> neighbors;
    bool visited;
};

/**
 * DFS遍历辅助函数
 * @param graph 图引用
 * @param node_id 当前节点ID
 * @param stack 结果栈
 */
void dfs_visit(vector<graph_node>& graph, int node_id, stack<int>& stack) {
    graph[node_id].visited = true;
    
    for (int neighbor : graph[node_id].neighbors) {
        if (!graph[neighbor].visited) {
            dfs_visit(graph, neighbor, stack);
        }
    }
    
    stack.push(node_id);
}

/**
 * 拓扑排序主函数
 * @param graph 图引用
 * @return 拓扑排序结果
 */
vector<int> topological_sort(vector<graph_node>& graph) {
    stack<int> stack;
    
    // 初始化所有节点为未访问
    for (auto& node : graph) {
        node.visited = false;
    }
    
    // 对每个未访问节点执行DFS
    for (auto& node : graph) {
        if (!node.visited) {
            dfs_visit(graph, node.id, stack);
        }
    }
    
    // 将栈中结果转为向量
    vector<int> result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    
    return result;
}

int main() {
    // 测试用例
    vector<graph_node> graph(6);
    for (int i = 0; i < 6; ++i) {
        graph[i].id = i;
    }
    
    // 构建图
    graph[0].neighbors = {1, 2};
    graph[1].neighbors = {3};
    graph[2].neighbors = {3, 4};
    graph[3].neighbors = {5};
    graph[4].neighbors = {5};
    
    // 执行拓扑排序
    vector<int> result = topological_sort(graph);
    
    // 输出结果
    cout << "拓扑排序结果: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}