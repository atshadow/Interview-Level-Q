class sopl {
    
    // Function to expand around center and find the longest palindrome
    public static String expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }

    // Function to find the longest palindromic substring
    public static String longestPalindrome(String s) {
        if (s == null || s.length() == 0) return "";
        
        String longest = "";
        
        for (int i = 0; i < s.length(); i++) {
            String oddPal = expandAroundCenter(s, i, i);      // Odd length palindrome
            String evenPal = expandAroundCenter(s, i, i + 1); // Even length palindrome
            
            if (oddPal.length() > longest.length()) longest = oddPal;
            if (evenPal.length() > longest.length()) longest = evenPal;
        }
        
        return longest;
    }

    // Main function
    public static void main(String[] args) {
        String str = "babad";
        System.out.println("Longest Palindromic Substring: " + longestPalindrome(str));
    }
}
