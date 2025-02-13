class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) return 0;
        
        // Use array instead of HashMap for better performance (assuming ASCII)
        int[] lastSeen = new int[128];
        // Initialize with -1 to handle first occurrence
        for (int i = 0; i < 128; i++) {
            lastSeen[i] = -1;
        }
        
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);
            // If character was seen and its last position is >= start
            if (lastSeen[currentChar] >= start) {
                start = lastSeen[currentChar] + 1;
            }
            lastSeen[currentChar] = end;
            maxLength = Math.max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test cases
        System.out.println(solution.lengthOfLongestSubstring("abcabcbb")); // Output: 3
        System.out.println(solution.lengthOfLongestSubstring("bbbbb"));    // Output: 1
        System.out.println(solution.lengthOfLongestSubstring("pwwkew"));   // Output: 3
        System.out.println(solution.lengthOfLongestSubstring(""));         // Output: 0
    }
}
