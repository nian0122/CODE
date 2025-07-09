/**
 * 双亲表示法的树结构实现
 * 功能：实现森林的双亲表示法存储及DFS/BFS遍历
 * 结构：
 *   - 每个节点包含数据和父节点索引
 *   - 通过parent字段表示树结构
 */
/*
双亲表示法
typedef struct{
    ElemTyoe date;
    int parent;
}PTNode;
typedef struct{
    PTNode node[MAX_TREE_SIZE];
    int nnum;
}PTree;

*/
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAX_TREE_SIZE 100

// 双亲表示法节点
typedef struct {
    char data;  // 节点数据
    int parent; // 父节点索引(-1表示根节点)
} PTNode;

// 双亲表示法树结构
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];  // 节点数组
    int nodeNum;  // 节点数量
} PTree;

// 初始化树
void initTree(PTree &tree) {
    tree.nodeNum = 0;
}

// 添加节点
void addNode(PTree &tree, char data, int parent) {
    if (tree.nodeNum >= MAX_TREE_SIZE) return;
    tree.nodes[tree.nodeNum].data = data;
    tree.nodes[tree.nodeNum].parent = parent;
    tree.nodeNum++;
}

// 递归DFS遍历(从指定节点开始)
void dfsRecursive(PTree &tree, int index) {
    if (index == -1 || index >= tree.nodeNum) return;
    cout << tree.nodes[index].data << " ";  // 访问当前节点
    
    // 遍历所有子节点
    for (int i = 0; i < tree.nodeNum; i++) {
        if (tree.nodes[i].parent == index) {
            dfsRecursive(tree, i);
        }
    }
}

// 非递归DFS遍历(使用栈)
void dfsIterative(PTree &tree, int root) {
    if (root == -1 || root >= tree.nodeNum) return;
    stack<int> s;
    s.push(root);
    
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        cout << tree.nodes[index].data << " ";
        
        // 将子节点逆序压栈(保证顺序访问)
        for (int i = tree.nodeNum - 1; i >= 0; i--) {
            if (tree.nodes[i].parent == index) {
                s.push(i);
            }
        }
    }
}

// BFS遍历(使用队列)
void bfs(PTree &tree, int root) {
    if (root == -1 || root >= tree.nodeNum) return;
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        cout << tree.nodes[index].data << " ";
        
        // 将当前节点的所有子节点加入队列
        for (int i = 0; i < tree.nodeNum; i++) {
            if (tree.nodes[i].parent == index) {
                q.push(i);
            }
        }
    }
}

/*
 * 测试用例
 * 构造如下树结构：
 *      A(0)
 *    / | \
 *  B(1)C(2)D(3)
 *  / \    |
 * E(4)F(5)G(6)
 */
int main() {
    PTree tree;
    initTree(tree);
    
    // 构建树(A为根节点)
    addNode(tree, 'A', -1);  // 0
    addNode(tree, 'B', 0);   // 1
    addNode(tree, 'C', 0);   // 2
    addNode(tree, 'D', 0);   // 3
    addNode(tree, 'E', 1);   // 4
    addNode(tree, 'F', 1);   // 5
    addNode(tree, 'G', 3);   // 6
    
    // 测试遍历
    cout << "递归DFS: ";
    dfsRecursive(tree, 0);
    cout << endl;
    
    cout << "非递归DFS: ";
    dfsIterative(tree, 0);
    cout << endl;
    
    cout << "BFS: ";
    bfs(tree, 0);
    cout << endl;
    
    return 0;
}
