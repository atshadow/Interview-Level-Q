#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) return 0;
        
        // Use vector instead of unordered_map for better performance
        std::vector<int> lastSeen(128, -1);
        
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            // If character was seen and its last position is >= start
            if (lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            lastSeen[s[end]] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};

// Example usage
int main() {
    Solution solution;
    
    // Test cases
    std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl; // Output: 3
    std::cout << solution.lengthOfLongestSubstring("bbbbb") << std::endl;    // Output: 1
    std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;   // Output: 3
    std::cout << solution.lengthOfLongestSubstring("") << std::endl;         // Output: 0
    
    return 0;
}
