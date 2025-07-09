/**
 * 孩子兄弟表示法的树结构实现
 * 功能：实现森林的孩子兄弟表示法存储及DFS/BFS遍历
 * 结构：
 *   - 每个节点包含数据、第一个孩子和下一个兄弟指针
 *   - 通过firstchild和nextsibling指针表示树结构
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
using namespace std;

// 孩子兄弟表示法节点
typedef struct CSNode {
    char data;  // 节点数据
    struct CSNode *firstchild, *nextsibling;  // 第一个孩子和下一个兄弟指针
} CSNode, *CSTree;

// 创建新节点
CSNode* createNode(char data) {
    CSNode* node = new CSNode();
    node->data = data;
    node->firstchild = node->nextsibling = nullptr;
    return node;
}

// 递归DFS遍历
void dfsRecursive(CSTree root) {
    if (!root) return;
    cout << root->data << " ";  // 访问当前节点
    dfsRecursive(root->firstchild);  // 递归遍历子树
    dfsRecursive(root->nextsibling);  // 递归遍历兄弟树
}

// 非递归DFS遍历(使用栈)
void dfsIterative(CSTree root) {
    if (!root) return;
    stack<CSTree> s;
    s.push(root);
    
    while (!s.empty()) {
        CSTree node = s.top();
        s.pop();
        cout << node->data << " ";
        
        // 先将右兄弟压栈，再压左孩子(保证左孩子先处理)
        if (node->nextsibling) s.push(node->nextsibling);
        if (node->firstchild) s.push(node->firstchild);
    }
}

// BFS遍历(使用队列)
void bfs(CSTree root) {
    if (!root) return;
    queue<CSTree> q;
    q.push(root);
    
    while (!q.empty()) {
        CSTree node = q.front();
        q.pop();
        cout << node->data << " ";
        
        // 将当前节点的所有兄弟加入队列
        CSTree sibling = node->nextsibling;
        while (sibling) {
            q.push(sibling);
            sibling = sibling->nextsibling;
        }
        
        // 将第一个孩子加入队列
        if (node->firstchild) q.push(node->firstchild);
    }
}

/*
 * 测试用例
 * 构造如下树结构：
 *      A
 *    / | \
 *   B  C  D
 *  / \    |
 * E   F   G
 */
int main() {
    // 构建树
    CSTree root = createNode('A');
    root->firstchild = createNode('B');
    root->firstchild->nextsibling = createNode('C');
    root->firstchild->nextsibling->nextsibling = createNode('D');
    
    root->firstchild->firstchild = createNode('E');
    root->firstchild->firstchild->nextsibling = createNode('F');
    
    root->firstchild->nextsibling->nextsibling->firstchild = createNode('G');
    
    // 测试遍历
    cout << "递归DFS: ";
    dfsRecursive(root);
    cout << endl;
    
    cout << "非递归DFS: ";
    dfsIterative(root);
    cout << endl;
    
    cout << "BFS: ";
    bfs(root);
    cout << endl;
    
    return 0;
}
