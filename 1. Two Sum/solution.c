#include <stdio.h>

void findTwoSum(int* nums, int numsSize, int target, int* result) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
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
    printf("Enter the array size: ");
    scanf("%d", &n);
    
    int* nums = (int*) malloc(n * sizeof(int));
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }
    
    int target;
    printf("Enter the target sum: ");
    scanf("%d", &target);
    
    int result[2];
    findTwoSum(nums, n, target, result);
    
    printf("Indices: [%d, %d]\n", result[0], result[1]);
    
    free(nums);
    return 0;
}
