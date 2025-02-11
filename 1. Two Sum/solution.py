def find_two_sum(nums, target):
    for i in range(len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []  # This line is theoretically unreachable as per problem statement

def main():
    n = int(input("Enter the array size: "))
    nums = []
    for i in range(n):
        num = int(input(f"Enter element {i + 1}: "))
        nums.append(num)
    target = int(input("Enter the target sum: "))
    result = find_two_sum(nums, target)
    print(f"Indices: [{result[0]}, {result[1]}]")

if __name__ == "__main__":
    main()
