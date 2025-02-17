#include <iostream>
#include <string>
using namespace std;

// Function to expand around center and find the longest palindrome
string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindromic substring
string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = "";
    
    for (int i = 0; i < s.length(); i++) {
        string oddPal = expandAroundCenter(s, i, i);     // Odd length palindrome
        string evenPal = expandAroundCenter(s, i, i + 1); // Even length palindrome
        
        if (oddPal.length() > longest.length()) longest = oddPal;
        if (evenPal.length() > longest.length()) longest = evenPal;
    }
    
    return longest;
}

// Main function
int main() {
    string str = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(str) << endl;
    return 0;
}
