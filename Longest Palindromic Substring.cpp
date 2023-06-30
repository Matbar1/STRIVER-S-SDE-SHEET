class Solution {
public:
  string longestPalindrome(std::string s) {
    int n = s.length();
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    
    int start = 0; // Starting index of the longest palindromic substring
    int maxLength = 1; // Length of the longest palindromic substring
    
    // Initialize the base cases for substrings of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    // Check for palindromic substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    
    // Check for palindromic substrings of length greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }
    
    // Extract and return the longest palindromic substring
    return s.substr(start, maxLength);
}
};