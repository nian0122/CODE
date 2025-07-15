// 插入排序实现（优化版）
// 使用折半查找优化插入位置查找

//核心是将为排序的数插入到已排序数列中合适位置
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