/**
 * 孩子表示法的树结构实现
 * 功能：实现森林的孩子表示法存储及DFS/BFS遍历
 * 结构：
 *   - 每个节点包含数据和指向第一个孩子的指针
 *   - 通过孩子链表表示树结构
 */
/*
孩子表示法
typedef struct CNode{
    ElemType date;
    struct CNode *next;
}CNode, *CNode;
typedef struct{
    CNode pNode[MAX_TREE_SIZE];
    int nnum;
}CTree;
*/
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAX_TREE_SIZE 100

// 孩子节点
typedef struct CNode {
    int index;  // 节点在数组中的索引
    struct CNode *next;  // 下一个孩子指针
} CNode;

// 表头节点
typedef struct {
    char data;  // 节点数据
    CNode *firstchild;  // 第一个孩子指针
} TNode;

// 孩子表示法树结构
typedef struct {
    TNode nodes[MAX_TREE_SIZE];  // 节点数组
    int nodeNum;  // 节点数量
} CTree;

// 初始化树
void initTree(CTree &tree) {
    tree.nodeNum = 0;
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        tree.nodes[i].firstchild = nullptr;
    }
}

// 添加节点
void addNode(CTree &tree, char data) {
    if (tree.nodeNum >= MAX_TREE_SIZE) return;
    tree.nodes[tree.nodeNum].data = data;
    tree.nodeNum++;
}

// 添加孩子关系
void addChild(CTree &tree, int parent, int child) {
    if (parent < 0 || parent >= tree.nodeNum || child < 0 || child >= tree.nodeNum) return;
    
    CNode *node = new CNode();
    node->index = child;
    node->next = nullptr;
    
    // 插入到孩子链表头部
    node->next = tree.nodes[parent].firstchild;
    tree.nodes[parent].firstchild = node;
}

// 递归DFS遍历
void dfsRecursive(CTree &tree, int index) {
    if (index < 0 || index >= tree.nodeNum) return;
    cout << tree.nodes[index].data << " ";  // 访问当前节点
    
    // 遍历所有孩子节点
    CNode *child = tree.nodes[index].firstchild;
    while (child) {
        dfsRecursive(tree, child->index);
        child = child->next;
    }
}

// 非递归DFS遍历(使用栈)
void dfsIterative(CTree &tree, int root) {
    if (root < 0 || root >= tree.nodeNum) return;
    stack<int> s;
    s.push(root);
    
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        cout << tree.nodes[index].data << " ";
        
        // 将孩子节点逆序压栈(保证顺序访问)
        CNode *child = tree.nodes[index].firstchild;
        stack<int> temp;
        while (child) {
            temp.push(child->index);
            child = child->next;
        }
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
}

// BFS遍历(使用队列)
void bfs(CTree &tree, int root) {
    if (root < 0 || root >= tree.nodeNum) return;
    queue<int> q;
    q.push(root);
    
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        cout << tree.nodes[index].data << " ";
        
        // 将当前节点的所有孩子加入队列
        CNode *child = tree.nodes[index].firstchild;
        while (child) {
            q.push(child->index);
            child = child->next;
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
    CTree tree;
    initTree(tree);
    
    // 添加节点
    addNode(tree, 'A');  // 0
    addNode(tree, 'B');  // 1
    addNode(tree, 'C');  // 2
    addNode(tree, 'D');  // 3
    addNode(tree, 'E');  // 4
    addNode(tree, 'F');  // 5
    addNode(tree, 'G');  // 6
    
    // 添加孩子关系
    addChild(tree, 0, 3);  // A->D
    addChild(tree, 0, 2);  // A->C
    addChild(tree, 0, 1);  // A->B
    addChild(tree, 1, 5);  // B->F
    addChild(tree, 1, 4);  // B->E
    addChild(tree, 3, 6);  // D->G
    
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