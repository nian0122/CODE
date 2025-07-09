#include <iostream>
using namespace std;

// 二叉排序树节点结构
typedef struct BSTNode {
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 初始化二叉排序树
void InitBST(BSTree &T) {
    T = nullptr;
}

// 查找操作(递归)
BSTNode* BSTSearch(BSTree T, int key) {
    if (T == nullptr || T->data == key) {
        return T;
    }
    if (key < T->data) {
        return BSTSearch(T->lchild, key);
    } else {
        return BSTSearch(T->rchild, key);
    }
}

// 插入操作(递归)
bool BSTInsert(BSTree &T, int key) {
    if (T == nullptr) {
        T = new BSTNode;
        T->data = key;
        T->lchild = T->rchild = nullptr;
        return true;
    } else if (key == T->data) {
        return false; // 已存在相同关键字
    } else if (key < T->data) {
        return BSTInsert(T->lchild, key);
    } else {
        return BSTInsert(T->rchild, key);
    }
}

// 删除操作辅助函数：找到右子树最小节点
BSTNode* FindMin(BSTNode* node) {
    while (node->lchild != nullptr) {
        node = node->lchild;
    }
    return node;
}

// 删除操作(递归)
bool BSTDelete(BSTree &T, int key) {
    if (T == nullptr) return false;
    
    if (key < T->data) {
        return BSTDelete(T->lchild, key);
    } else if (key > T->data) {
        return BSTDelete(T->rchild, key);
    } else {
        // 找到要删除的节点
        if (T->lchild == nullptr) {
            BSTNode* temp = T->rchild;
            delete T;
            T = temp;
        } else if (T->rchild == nullptr) {
            BSTNode* temp = T->lchild;
            delete T;
            T = temp;
        } else {
            // 节点有两个子节点
            BSTNode* temp = FindMin(T->rchild);
            T->data = temp->data;
            BSTDelete(T->rchild, temp->data);
        }
        return true;
    }
}

// 中序遍历(递归)
void InOrderTraverse(BSTree T) {
    if (T != nullptr) {
        InOrderTraverse(T->lchild);
        cout << T->data << " ";
        InOrderTraverse(T->rchild);
    }
}

// 测试函数
void TestBST() {
    BSTree tree;
    InitBST(tree);
    
    // 测试插入
    BSTInsert(tree, 50);
    BSTInsert(tree, 30);
    BSTInsert(tree, 20);
    BSTInsert(tree, 40);
    BSTInsert(tree, 70);
    BSTInsert(tree, 60);
    BSTInsert(tree, 80);
    
    cout << "中序遍历结果: ";
    InOrderTraverse(tree);
    cout << endl;
    
    // 测试查找
    cout << "查找40: " << (BSTSearch(tree, 40) ? "找到" : "未找到") << endl;
    cout << "查找90: " << (BSTSearch(tree, 90) ? "找到" : "未找到") << endl;
    
    // 测试删除
    BSTDelete(tree, 20); // 删除叶子节点
    BSTDelete(tree, 30); // 删除有一个子节点的节点
    BSTDelete(tree, 50); // 删除有两个子节点的节点
    
    cout << "删除后中序遍历: ";
    InOrderTraverse(tree);
    cout << endl;
}

int main() {
    TestBST();
    return 0;
}
