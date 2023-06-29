class Solution {
public:
    int uniquePaths(int m, int n) {
    // Create a 2D vector to store the number of paths
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    
    // Set the base cases
    dp[0][0] = 1;
    
    // Fill the first row with 1's
    for (int i = 1; i < n; i++)
        dp[0][i] = 1;
    
    // Fill the first column with 1's
    for (int i = 1; i < m; i++)
        dp[i][0] = 1;
    
    // Calculate the number of paths for each cell
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    // Return the number of paths for the last cell
    return dp[m - 1][n - 1];
}
};