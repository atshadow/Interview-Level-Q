#include <stdio.h>
#include <string.h>

// Function to expand around center and find the longest palindrome
void expandAroundCenter(char s[], int left, int right, int *start, int *maxLen) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    
    int length = right - left - 1;
    if (length > *maxLen) {
        *start = left + 1;
        *maxLen = length;
    }
}

// Function to find the longest palindromic substring
void longestPalindrome(char s[]) {
    int len = strlen(s);
    if (len == 0) return;
    
    int start = 0, maxLen = 0;
    
    for (int i = 0; i < len; i++) {
        expandAroundCenter(s, i, i, &start, &maxLen);     // Odd length palindrome
        expandAroundCenter(s, i, i + 1, &start, &maxLen); // Even length palindrome
    }
    
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char str[] = "babad";
    longestPalindrome(str);
    return 0;
}
