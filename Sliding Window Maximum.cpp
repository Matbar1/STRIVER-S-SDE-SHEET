class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements that are out of the current window
        if (!window.empty() && window.front() == i - k)
            window.pop_front();

        // Remove elements smaller than the current element from the back of the window
        while (!window.empty() && nums[i] > nums[window.back()])
            window.pop_back();

        // Add the current element to the window
        window.push_back(i);

        // Add the maximum element to the result
        if (i >= k - 1)
            result.push_back(nums[window.front()]);
    }

    return result;
}
};