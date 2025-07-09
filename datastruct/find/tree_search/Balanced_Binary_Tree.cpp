#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// 创建新节点
AVLNode* createNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// 获取节点高度
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// 计算平衡因子
int getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// 更新节点高度
void updateHeight(AVLNode* node) {
    if (node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// 右旋
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// 左旋
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// 平衡节点
AVLNode* balanceNode(AVLNode* node) {
    if (!node) return NULL;

    updateHeight(node);
    int balance = getBalanceFactor(node);

    // 左左情况
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }

    // 右右情况
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }

    // 左右情况
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // 右左情况
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// 插入节点
AVLNode* insertNode(AVLNode* node, int data) {
    if (!node) return createNode(data);

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    } else {
        return node; // 不允许重复值
    }

    return balanceNode(node);
}

// 查找最小节点
AVLNode* findMinNode(AVLNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

// 删除节点
AVLNode* deleteNode(AVLNode* node, int data) {
    if (!node) return NULL;

    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    return balanceNode(node);
}

// 查找节点
AVLNode* searchNode(AVLNode* node, int data) {
    while (node) {
        if (data == node->data) {
            return node;
        } else if (data < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return NULL;
}

// 中序遍历
void inOrderTraversal(AVLNode* node) {
    if (!node) return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}

// 释放树内存
void freeTree(AVLNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    AVLNode* root = NULL;
    
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("中序遍历结果: ");
    inOrderTraversal(root);
    printf("\n");

    printf("删除节点30\n");
    root = deleteNode(root, 30);

    printf("中序遍历结果: ");
    inOrderTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}