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
孩子表示法
typedef struct CNode{
    ElemType date;
    struct CNode *next;
}CNode, *CNode;
typedef struct{
    CNode pNode[MAX_TREE_SIZE];
    int nnum;
}CTree;
孩子兄弟表示法
typedef struct CSNode{
    EleType data;
    struct CSNOde *firstchild,*nextsibling;
}CSNode ,*CSTree;
*/