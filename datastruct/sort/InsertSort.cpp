// 插入排序实现（优化版）
// 使用折半查找优化插入位置查找

//核心是将为排序的数插入到已排序数列中合适位置
#include <cstdlib>
#include <cstdio>
typedef int Elemtype;

void InsertSort(Elemtype A[], int n) {
    int current_idx, move_idx, low, high, mid;
    Elemtype tmp_val;
    // 从第二个元素开始排序
    for(current_idx=1; current_idx < n; current_idx++) {
        // 如果当前元素小于前一个元素，需要插入
        if(A[current_idx] < A[current_idx-1]) {
            tmp_val = A[current_idx]; // 保存当前元素
            // 使用折半查找确定插入位置
            low = 0;
            high = current_idx-1;
            while(low <= high) {
                mid = (low + high) / 2;
                if(tmp_val < A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // 移动元素
            for(move_idx = current_idx-1; move_idx >= high+1; --move_idx) {
                A[move_idx+1] = A[move_idx];
            }
            // 插入元素到正确位置
            A[high+1] = tmp_val;
        }
    }
}

void InsertSort(Elemtype A[], int n) {
    int current_idx, move_idx;
    Elemtype tmp_val;
    // 从第二个元素开始排序
    for(current_idx=1; current_idx < n; current_idx++) {
        // 如果当前元素小于前一个元素，需要插入
        if(A[current_idx] < A[current_idx-1]) {
            tmp_val=A[current_idx]; // 设置哨兵
            // 向后移动比哨兵大的元素
            for(move_idx=current_idx-1; tmp_val < A[move_idx]; --move_idx)
                A[move_idx+1]=A[move_idx];
            // 插入哨兵元素到正确位置
            A[move_idx+1]=tmp_val;
        }
    }
}

// 链表节点结构
typedef struct Node {
    Elemtype data;
    struct Node* next;
} Node;

// 创建新节点
Node* create_node(Elemtype val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

// 链表插入排序
Node* insert_sort_list(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* dummy = create_node(0); // 哑节点
    dummy->next = head;
    Node* last_sorted = head;    // 已排序部分的最后一个节点
    Node* curr = head->next;     // 当前待排序节点
    
    while(curr != NULL) {
        if(last_sorted->data <= curr->data) {
            last_sorted = last_sorted->next;
        } else {
            Node* prev = dummy;
            // 找到插入位置
            while(prev->next->data <= curr->data) {
                prev = prev->next;
            }
            // 执行插入
            last_sorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = last_sorted->next;
    }
    return dummy->next;
}

// 测试链表插入排序
void test_insert_sort_list() {
    printf("测试链表插入排序:\n");
    int arr[] = {5, 3, 8, 6, 2, 7, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // 创建链表
    Node* head = create_node(arr[0]);
    Node* curr = head;
    for(int i=1; i<n; i++) {
        curr->next = create_node(arr[i]);
        curr = curr->next;
    }
    
    // 排序前
    printf("排序前: ");
    curr = head;
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    
    // 执行排序
    head = insert_sort_list(head);
    
    // 排序后
    printf("排序后: ");
    curr = head;
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    
    // 释放内存
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}