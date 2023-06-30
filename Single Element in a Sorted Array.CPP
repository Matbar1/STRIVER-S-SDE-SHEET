class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if mid and mid + 1 are equal
        if (nums[mid] == nums[mid + 1]) {
            // If the subarray from mid to right has even length,
            // the single element is on the right side, so update left.
            // Otherwise, it's on the left side, so update right.
            if ((right - mid) % 2 == 0) {
                left = mid + 2;
            } else {
                right = mid - 1;
            }
        } else if (nums[mid] == nums[mid - 1]) {
            // Similar logic as above, but checking if mid and mid - 1 are equal.
            if ((right - mid + 1) % 2 == 0) {
                left = mid + 1;
            } else {
                right = mid - 2;
            }
        } else {
            // If neither mid and its adjacent elements are equal,
            // then mid is the single element.
            return nums[mid];
        }
    }

    // The single element is at the index left.
    return nums[left];
}
};