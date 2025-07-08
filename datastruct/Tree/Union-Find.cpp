#include <iostream>

// 使用一个常量来定义并查集的大小
const int SIZE = 10;

/**
 * @brief 初始化并查集数组。
 * 初始时，每个元素自成一个集合，大小为1。
 * 我们用-1来表示根节点和集合大小。
 * @param parent 代表集合的数组。
 */
void initial(int parent[]) {
    for (int i = 0; i < SIZE; ++i) {
        parent[i] = -1;
    }
}

/**
 * @brief 查找元素 i 的根节点（带路径压缩）。
 * @param parent 代表集合的数组。
 * @param i 要查找的元素。
 * @return 元素 i 的根节点。
 */
int find_set(int parent[], int i) {
    // 如果 parent[i] 是负数，说明 i 就是根节点
    if (parent[i] < 0) {
        return i;
    }
    // 递归查找根节点，并把路径上的节点直接连到根上（路径压缩）
    return parent[i] = find_set(parent, parent[i]);
}

/**
 * @brief 合并两个元素所在的集合（按大小合并）。
 * @param parent 代表集合的数组。
 * @param i 第一个元素。
 * @param j 第二个元素。
 */
void unite_sets(int parent[], int i, int j) {
    int root1 = find_set(parent, i);
    int root2 = find_set(parent, j);

    if (root1 != root2) {
        // parent[root]的负值代表集合大小
        // 将小集合合并到大集合
        if (parent[root1] < parent[root2]) { // root1 的集合更大
            parent[root1] += parent[root2]; // 更新大集合的大小
            parent[root2] = root1;          // 小集合的根指向大集合的根
        } else {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
}

// --- 用例部分 ---
int main() {


    std::cout << "--- 并查集用例测试 (基于数组的风格) ---" << std::endl;
    
    // 声明并查集数组
    int parent[SIZE];

    // 1. 初始化
    initial(parent);
    std::cout << "初始化 " << SIZE << " 个元素的并查集。" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    // 2. 合并集合
    std::cout << "合并 (0, 1)..." << std::endl;
    unite_sets(parent, 0, 1);
    std::cout << "合并 (2, 3)..." << std::endl;
    unite_sets(parent, 2, 3);
    std::cout << "合并 (0, 2)..." << std::endl;
    unite_sets(parent, 0, 2); // 现在 {0, 1, 2, 3} 在一个集合
    std::cout << "合并 (5, 6)..." << std::endl;
    unite_sets(parent, 5, 6);
    std::cout << "--------------------------------" << std::endl;

    // 3. 检查连通性
    std::cout << "检查连通性:" << std::endl;
    std::cout << "1 和 3 是否连通? " << (find_set(parent, 1) == find_set(parent, 3) ? "是" : "否") << std::endl;
    std::cout << "0 和 5 是否连通? " << (find_set(parent, 0) == find_set(parent, 5) ? "是" : "否") << std::endl;
    std::cout << "5 和 6 是否连通? " << (find_set(parent, 5) == find_set(parent, 6) ? "是" : "否") << std::endl;
    std::cout << "--------------------------------" << std::endl;

    // 4. 查看根节点和集合大小
    int root_of_1 = find_set(parent, 1);
    int root_of_5 = find_set(parent, 5);
    std::cout << "元素 1 所在集合的根是: " << root_of_1 << ", 大小是: " << -parent[root_of_1] << std::endl;
    std::cout << "元素 5 所在集合的根是: " << root_of_5 << ", 大小是: " << -parent[root_of_5] << std::endl;

    return 0;
}