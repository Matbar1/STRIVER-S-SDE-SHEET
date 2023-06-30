class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

    if (totalSum % 2 != 0) {
        return false;  // If the total sum is odd, we can't have equal subsets
    }

    int targetSum = totalSum / 2;

    std::vector<bool> dp(targetSum + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = targetSum; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[targetSum];
}
};