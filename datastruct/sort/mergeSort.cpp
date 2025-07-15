#include <iostream>
#include <cstring>
using namespace std;

// Internal merge function
static void merge(int input_array[], int temp_array[], int start_index, int middle_index, int end_index) {
    int left_index, right_index, merged_index;
    
    // Copy elements to auxiliary array
    for (merged_index = start_index; merged_index <= end_index; merged_index++) {
        temp_array[merged_index] = input_array[merged_index];
    }
    
    // Merge two sorted subarrays
    for (left_index = start_index, right_index = middle_index + 1, merged_index = left_index; 
         left_index <= middle_index && right_index <= end_index; merged_index++) {
        if (temp_array[left_index] < temp_array[right_index]) {
            input_array[merged_index] = temp_array[left_index++];
        } else {
            input_array[merged_index] = temp_array[right_index++];
        }
    }
    
    // Copy remaining elements from left subarray
    while (left_index <= middle_index) {
        input_array[merged_index++] = temp_array[left_index++];
    }
    
    // Copy remaining elements from right subarray
    while (right_index <= end_index) {
        input_array[merged_index++] = temp_array[right_index++];
    }
}

// Internal merge sort function
static void merge_sort_recursive(int input_array[], int temp_array[], int start_index, int end_index) {
    if (start_index < end_index) {
        int middle_index = (start_index + end_index) >> 1;
        merge_sort_recursive(input_array, temp_array, start_index, middle_index);
        merge_sort_recursive(input_array, temp_array, middle_index + 1, end_index);
        merge(input_array, temp_array, start_index, middle_index, end_index);
    }
}

// Test function
// Public interface for merge sort
void merge_sort(int input_array[], int array_size) {
    if (array_size <= 1) return;
    
    int* temp_array = new int[array_size];
    merge_sort_recursive(input_array, temp_array, 0, array_size - 1);
    delete[] temp_array;
}

void test_merge_sort() {
    const int array_size = 10;
    int numbers_array[array_size] = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7};
    
    cout << "Original array: ";
    for (int index = 0; index < array_size; index++) {
        cout << numbers_array[index] << " ";
    }
    cout << endl;
    
    merge_sort(numbers_array, array_size);
    
    cout << "Sorted array: ";
    for (int index = 0; index < array_size; index++) {
        cout << numbers_array[index] << " ";
    }
    cout << endl;
}

int main() {
    test_merge_sort();
    return 0;
}
