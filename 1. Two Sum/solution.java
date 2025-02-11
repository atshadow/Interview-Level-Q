import java.util.Scanner;

class solution {
    public static int[] findTwoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[0]; // This line is theoretically unreachable as per problem statement
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter the array size: ");
        int n = in.nextInt();
        
        int[] nums = new int[n];
        System.out.println("Enter " + n + " array elements:");
        for (int i = 0; i < n; i++) {
            System.out.print("Element " + (i + 1) + ": ");
            nums[i] = in.nextInt();
        }
        
        System.out.print("Enter the target sum: ");
        int target = in.nextInt();
        
        int[] result = findTwoSum(nums, target);
        
        System.out.println("Indices: [" + result[0] + ", " + result[1] + "]");
        
        in.close();
    }
}
