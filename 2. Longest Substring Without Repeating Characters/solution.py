# This function finds the length of the longest substring without repeating characters
def length_of_longest_substring(s):
    # Dictionary to store the last position of each character
    char_map = {}
    # Left pointer of the sliding window
    left = 0
    # Length of longest valid substring found so far
    max_length = 0
    
    # Right pointer iterates through the string
    for right in range(len(s)):
        char = s[right]
        # If we find a repeating character within our current window,
        # move left pointer to position after its last occurrence
        if char in char_map and char_map[char] >= left:
            left = char_map[char] + 1
            
        # Update last position of current character
        char_map[char] = right
        
        # Calculate length of current window
        current_length = right - left + 1
        # Update max_length if current window is longer
        if current_length > max_length:
            max_length = current_length
            
    return max_length

# Example usage:
print(length_of_longest_substring("abcabcbb"))   # Output: 3
print(length_of_longest_substring("bbbbb"))       # Output: 1
print(length_of_longest_substring("pwwkew"))      # Output: 3
