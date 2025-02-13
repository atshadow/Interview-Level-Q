import java.util.Scanner;

public class Median {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Ensure nums1 is the shorter array
        if (nums1.length > nums2.length) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        
        int m = nums1.length;
        int n = nums2.length;
        int left = 0, right = m;
        
        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            double maxLeftX = (partitionX == 0) ? Double.NEGATIVE_INFINITY : nums1[partitionX - 1];
            double minRightX = (partitionX == m) ? Double.POSITIVE_INFINITY : nums1[partitionX];
            
            double maxLeftY = (partitionY == 0) ? Double.NEGATIVE_INFINITY : nums2[partitionY - 1];
            double minRightY = (partitionY == n) ? Double.POSITIVE_INFINITY : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2;
                } else {
                    return Math.max(maxLeftX, maxLeftY);
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
    
    public static int[] getArrayInput(Scanner scanner, String arrayName) {
        while (true) {
            try {
                System.out.print("Enter " + arrayName + " (space-separated numbers): ");
                String[] inputs = scanner.nextLine().trim().split("\\s+");
                int[] result = new int[inputs.length];
                
                for (int i = 0; i < inputs.length; i++) {
                    result[i] = Integer.parseInt(inputs[i]);
                }
                
                return result;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter numbers only.");
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Median solution = new Median();
        
        int[] nums1 = getArrayInput(scanner, "first array");
        int[] nums2 = getArrayInput(scanner, "second array");
        
        double median = solution.findMedianSortedArrays(nums1, nums2);
        System.out.println("The median is: " + median);
        
        scanner.close();
    }
} 