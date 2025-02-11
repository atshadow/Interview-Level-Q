#include <iostream>
using namespace std;

void findTwoSum(int* nums, int n, int target, int* result) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;
    
    int* nums = new int[n];
    cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }
    
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    
    int result[2];
    findTwoSum(nums, n, target, result);
    
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    
    delete[] nums;
    return 0;
}
