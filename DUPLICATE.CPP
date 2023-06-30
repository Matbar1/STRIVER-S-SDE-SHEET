class Solution {
public:
   int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Finding the intersection point of slow and fast pointers
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Finding the entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
};