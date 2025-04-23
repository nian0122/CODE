#include <iostream>
#include <queue>
typedef int Elemtype;
typedef struct BiNode{
    Elemtype data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

BiTree CreateBiTree() {
    return NULL;
}

void InsertNode(BiTree &T, Elemtype x){
    if(!T){
        T = new BiNode{
            x,
            nullptr,
            nullptr
        };
    }else if(x < T->data) {
        InsertNode(T->lchild, x);
    } else{
        InsertNode(T->rchild, x);
    }
}

void visit(BiTree node){
    std::cout << "Node:" << node->data 
              << " Left:" << (node->lchild ? node->lchild->data : -1)
              << " Right:" << (node->rchild ? node->rchild->data : -1)
              << std::endl;
}

void PreOrder(BiTree T){
    if(T){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void LevelOrder(BiTree T){
    std::queue<BiTree> Q;
    BiTree q;
    Q.push(T);
    while(!Q.empty()){
        q = Q.front();
        Q.pop();
        visit(q);
        if(q->lchild != nullptr){
            Q.push(q->lchild);
        }
        if(q->rchild != nullptr){
            Q.push(q->rchild);
        }
    }
}

int main() {
    // 创建空树
    BiTree root = CreateBiTree();

    // 插入测试数据（构建二叉搜索树）
//       5
//     /   \
//    3     7
//   / \   / \
//  2  4  6  8
    InsertNode(root, 5);   // 根节点
    InsertNode(root, 3);   // 左子
    InsertNode(root, 7);   // 右子
    InsertNode(root, 2);   // 3的左子
    InsertNode(root, 4);   // 3的右子
    InsertNode(root, 6);   // 7的左子
    InsertNode(root, 8);   // 7的右子

    // 验证遍历结果
    std::cout << "\n========== PreOrder ==========\n";
    PreOrder(root);

    std::cout << "\n========== InOrder ==========\n";
    InOrder(root);

    std::cout << "\n========== PostOrder ==========\n";
    PostOrder(root);

    std::cout << "\n========== LevelOrder ==========\n";
    LevelOrder(root);

    return 0;
}
