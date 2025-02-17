def expand_around_center(s, left, right):
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return s[left + 1:right]  # Return the palindrome substring

def longest_palindromic_substring(s):
    if not s or len(s) == 1:
        return s
    
    longest = ""
    
    for i in range(len(s)):
        # Check for odd-length palindrome
        odd_palindrome = expand_around_center(s, i, i)
        if len(odd_palindrome) > len(longest):
            longest = odd_palindrome
        
        # Check for even-length palindrome
        even_palindrome = expand_around_center(s, i, i + 1)
        if len(even_palindrome) > len(longest):
            longest = even_palindrome
    
    return longest

# Example test cases
print(longest_palindromic_substring("babad"))  # Output: "bab" or "aba"
print(longest_palindromic_substring("cbbd"))   # Output: "bb"
