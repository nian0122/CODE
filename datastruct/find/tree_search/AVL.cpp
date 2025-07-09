#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int data;
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
    Color color;
} RBNode;

typedef struct RBTree {
    RBNode* root;
    RBNode* nil; // 哨兵节点
} RBTree;

RBNode* createNode(int data, Color color) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    node->color = color;
    return node;
}

RBTree* createRBTree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->nil = createNode(0, BLACK);
    tree->root = tree->nil;
    return tree;
}

void leftRotate(RBTree* tree, RBNode* x) {
    RBNode* nil = tree->nil;
    RBNode* y = x->right;
    x->right = y->left;

    if (y->left != nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(RBTree* tree, RBNode* y) {
    RBNode* nil = tree->nil;
    RBNode* x = y->left;
    y->left = x->right;

    if (x->right != nil) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == nil) {
        tree->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void insertFixup(RBTree* tree, RBNode* z) {
    RBNode* nil = tree->nil;
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            if (y->color == RED) {
                // Case 1: 叔叔节点是红色
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    // Case 2: 叔叔节点是黑色，且z是右孩子
                    z = z->parent;
                    leftRotate(tree, z);
                }
                // Case 3: 叔叔节点是黑色，且z是左孩子
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(tree, z->parent->parent);
            }
        } else {
            // 对称情况
            RBNode* y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

RBNode* minimum(RBTree* tree, RBNode* node) {
    RBNode* nil = tree->nil;
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

void deleteFixup(RBTree* tree, RBNode* x) {
    RBNode* nil = tree->nil;
    RBNode* root = tree->root;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            if (w->color == RED) {
                // Case 1: x的兄弟节点w是红色
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                // Case 2: w的两个孩子都是黑色
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    // Case 3: w的左孩子是红色，右孩子是黑色
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree, w);
                    w = x->parent->right;
                }
                // Case 4: w的右孩子是红色
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, x->parent);
                x = root;
            }
        } else {
            // 对称情况
            RBNode* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void inOrderHelper(RBNode* node, RBNode* nil) {
    if (node != nil) {
        inOrderHelper(node->left, nil);
        printf("%d(%c) ", node->data, node->color == RED ? 'R' : 'B');
        inOrderHelper(node->right, nil);
    }
}

void inOrder(RBTree* tree) {
    inOrderHelper(tree->root, tree->nil);
    printf("\n");
}

void transplant(RBTree* tree, RBNode* u, RBNode* v) {
    RBNode* nil = tree->nil;
    if (u->parent == nil) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void insert(RBTree* tree, int data) {
    RBNode* z = createNode(data, RED);
    RBNode* nil = tree->nil;
    RBNode* y = nil;
    RBNode* x = tree->root;

    while (x != nil) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nil) {
        tree->root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = nil;
    z->right = nil;
    insertFixup(tree, z);
}

RBNode* search(RBTree* tree, int data) {
    RBNode* current = tree->root;
    RBNode* nil = tree->nil;
    while (current != nil) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

void remove(RBTree* tree, int data) {
    RBNode* z = tree->root;
    RBNode* nil = tree->nil;
    while (z != nil) {
        if (data == z->data) {
            break;
        } else if (data < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }

    if (z == nil) return; // 未找到节点

    RBNode* y = z;
    RBNode* x;
    Color yOriginalColor = y->color;

    if (z->left == nil) {
        x = z->right;
        transplant(tree, z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(tree, z, z->left);
    } else {
        y = minimum(tree, z->right);
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (yOriginalColor == BLACK) {
        deleteFixup(tree, x);
    }

    free(z);
}

int main() {
    RBTree* tree = createRBTree();

    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 15);
    insert(tree, 25);
    insert(tree, 5);

    printf("中序遍历结果: ");
    inOrder(tree);

    printf("删除节点20\n");
    remove(tree, 20);

    printf("中序遍历结果: ");
    inOrder(tree);

    return 0;
}
