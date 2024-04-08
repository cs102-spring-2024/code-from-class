#include <iostream>
#include <vector>
using namespace std;

const int NOT_FOUND = -1;
const int LARGE_VECTOR_SIZE = 700000000;

vector<int> large_random_vector(int size) {
    vector<int> nums;
    int curr = 0;

    for (int i = 0; i < size; i++) {
        nums.push_back(curr);
        curr += (rand() % 5) + 1;
    }

    return nums;
}

int binary_search_recursive(vector<int> & nums, int target, int start_index, int end_index) {
    if (start_index > end_index)
        return NOT_FOUND;

    int mid = (start_index + end_index) / 2;

    if (nums[mid] == target)
        return mid;

    if (nums[mid] > target)
        return binary_search_recursive(nums, target, start_index, mid -1);
    
    return binary_search_recursive(nums, target, mid + 1, end_index);
}

int binary_search(vector<int> & nums, int target) {
    return binary_search_recursive(nums, target, 0, nums.size() - 1);
}

int linear_search(vector<int> & nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            return i;
    }
    return NOT_FOUND;
}

int main() {
    vector<int> nums = {-32, -22, -21, -4, 0, 23, 28, 45, 59, 60, 61, 67};

    // int index_of_28 = binary_search(nums, 28);
    // cout << "The index of 28: " << index_of_28 << endl;

    // int index_of_neg5 = binary_search(nums, -5);
    // cout << "The index of -5: " << index_of_neg5 << endl;

    // int index_of_500 = binary_search(nums, 500);
    // cout << "The index of 500: " << index_of_500 << endl;


    vector<int> rand_vec = large_random_vector(LARGE_VECTOR_SIZE);

    int num_to_find = 83775923;

    cout << "Starting binary search..." << endl;
    int index = binary_search(rand_vec, num_to_find);
    cout << "End binary search. Index is: " << index << endl;

    cout << "Starting linear search..." << endl;
    int index_linear = linear_search(rand_vec, num_to_find);
    cout << "End linear search. Index is: " << index_linear << endl;

}