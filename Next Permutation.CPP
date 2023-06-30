class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;

        // Find the next larger element from the right
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }

        // Swap the two elements
        swap(nums[i], nums[j]);
    }
    

    // Reverse the remaining elements
    reverse(nums.begin() + i + 1, nums.end());
}};