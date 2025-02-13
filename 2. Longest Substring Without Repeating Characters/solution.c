#include <stdio.h>
#include <string.h>

int length_of_longest_substring(char *s) {
    int char_map[256] = {0}; // Assuming ASCII characters
    int left = 0, max_length = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char current_char = s[right];
        if (char_map[current_char] > left) {
            left = char_map[current_char];
        }
        char_map[current_char] = right + 1; // Store the next index
        int current_length = right - left + 1;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    return max_length;
}

// Example usage
int main() {
    printf("%d\n", length_of_longest_substring("abcabcbb")); // Output: 3
    printf("%d\n", length_of_longest_substring("bbbbb"));     // Output: 1
    printf("%d\n", length_of_longest_substring("pwwkew"));    // Output: 3
    return 0;
}
