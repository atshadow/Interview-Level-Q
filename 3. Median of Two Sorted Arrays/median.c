#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_INPUT 1000

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the shorter array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int left = 0, right = m;
    
    while (left <= right) {
        int partitionX = (left + right) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;
        
        double maxLeftX = (partitionX == 0) ? -DBL_MAX : nums1[partitionX - 1];
        double minRightX = (partitionX == m) ? DBL_MAX : nums1[partitionX];
        
        double maxLeftY = (partitionY == 0) ? -DBL_MAX : nums2[partitionY - 1];
        double minRightY = (partitionY == n) ? DBL_MAX : nums2[partitionY];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                double maxLeft = maxLeftX > maxLeftY ? maxLeftX : maxLeftY;
                double minRight = minRightX < minRightY ? minRightX : minRightY;
                return (maxLeft + minRight) / 2;
            } else {
                return maxLeftX > maxLeftY ? maxLeftX : maxLeftY;
            }
        }
        else if (maxLeftX > minRightY) {
            right = partitionX - 1;
        }
        else {
            left = partitionX + 1;
        }
    }
    return 0.0; // for compilation, should never reach here
}

int* getArrayInput(const char* arrayName, int* size) {
    char input[MAX_INPUT];
    int* numbers = malloc(MAX_INPUT * sizeof(int));
    *size = 0;
    
    while (1) {
        printf("Enter %s (space-separated numbers): ", arrayName);
        fgets(input, MAX_INPUT, stdin);
        
        char* token = strtok(input, " \n");
        *size = 0;
        int valid = 1;
        
        while (token != NULL) {
            char* endptr;
            numbers[*size] = strtol(token, &endptr, 10);
            
            if (*endptr != '\0' && *endptr != '\n') {
                valid = 0;
                break;
            }
            
            (*size)++;
            token = strtok(NULL, " \n");
        }
        
        if (valid) break;
        printf("Invalid input. Please enter numbers only.\n");
    }
    
    return numbers;
}

int main() {
    int size1, size2;
    int* nums1 = getArrayInput("first array", &size1);
    int* nums2 = getArrayInput("second array", &size2);
    
    double median = findMedianSortedArrays(nums1, size1, nums2, size2);
    printf("The median is: %f\n", median);
    
    free(nums1);
    free(nums2);
    return 0;
} 