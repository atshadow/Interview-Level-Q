def findMedianSortedArrays(nums1: list[int], nums2: list[int]):
    # Ensure nums1 is the shorter array for optimization
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1
    
    m, n = len(nums1), len(nums2)
    left, right = 0, m
    
    while left <= right:
        # Partition points for both arrays
        partitionX = (left + right) // 2
        partitionY = (m + n + 1) // 2 - partitionX
        
        # Get the elements around partition points
        maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX - 1]
        minRightX = float('inf') if partitionX == m else nums1[partitionX]
        
        maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY - 1]
        minRightY = float('inf') if partitionY == n else nums2[partitionY]
        
        # Check if we found the correct partition
        if maxLeftX <= minRightY and maxLeftY <= minRightX:
            # If total length is odd
            if (m + n) % 2 == 1:
                return max(maxLeftX, maxLeftY)
            # If total length is even
            else:
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2
        # Adjust the partition
        elif maxLeftX > minRightY:
            right = partitionX - 1
        else:
            left = partitionX + 1
    
    raise ValueError("Input arrays are not sorted")

# Get input from user
def get_array_input(array_name):
    while True:
        try:
            input_str = input(f"Enter {array_name} (space-separated numbers): ")
            # Convert input string to list of integers
            return [int(x) for x in input_str.strip().split()]
        except ValueError:
            print("Invalid input. Please enter numbers separated by spaces.")

# Get both arrays from user
nums1 = get_array_input("first array")
nums2 = get_array_input("second array")

# Calculate and display the median
result = findMedianSortedArrays(nums1, nums2)
print(f"The median is: {result}")
