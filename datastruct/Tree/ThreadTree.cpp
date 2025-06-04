#include<iostream>
typedef int Elemtype;
typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode,*ThreadTree;

void InThread(ThreadTree T, ThreadNode *&pre);

void visit(ThreadTree node){
    std::cout << "Node:" << node->data 
              << " Left:" << (node->lchild ? node->lchild->data : -1)
              << " Right:" << (node->rchild ? node->rchild->data : -1)
              << std::endl;
}

void InsertNode(ThreadTree &T, Elemtype x){
    if(!T){
        T = new ThreadNode{
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

void CreateInThread(ThreadTree T){
    ThreadNode *pre = nullptr;
    if(T!=nullptr){
        InThread(T,pre);
        pre->rchild=nullptr;
        pre->rtag=1;
    }
}

void InThread(ThreadTree T, ThreadNode *&pre){
    if(T == nullptr){
        return;
    }
    InThread(T->lchild,pre);
    if(T->lchild == nullptr){
        T->lchild = pre;
        T->ltag = 1;
    }
    if(pre != nullptr && pre->rchild == nullptr){
        pre->rchild = T;
        pre->rtag = 1;
    }
    pre = T;
    InThread(T->rchild,pre);
}

void InOrder(ThreadTree T){
    while(T != nullptr){
        while(T->ltag == 0){
            T = T->lchild;
        }
        visit(T);
        while(T->rchild != nullptr && T->rtag == 1){
            T = T->rchild;
            visit(T);
        }
        T = T->rchild;
    }

}

int main() {
    ThreadTree root = nullptr;

    // 插入测试数据（构建二叉搜索树）
    InsertNode(root, 5);
    InsertNode(root, 3);
    InsertNode(root, 7);
    InsertNode(root, 2);
    InsertNode(root, 4);
    InsertNode(root, 6);
    InsertNode(root, 8);

    // 中序线索化二叉树

    CreateInThread(root);   // 执行线索化

    // 打印线索化后的中序遍历结果
    std::cout << "中序线索遍历结果：" << std::endl;
    InOrder(root);      // 应输出：2 3 4 5 6 7 8

    return 0;
}