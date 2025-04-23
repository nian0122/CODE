typedef int Elemtype;
typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild, *rcild;
    int ltag, rtag;
}ThreadNode,*ThreadTree;