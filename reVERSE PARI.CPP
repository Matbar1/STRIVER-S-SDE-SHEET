class Solution {
public:
int mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    vector<int> merged(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if ((long long)nums[i] > 2LL * nums[j]) {
            count += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }

    i = left;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            merged[k++] = nums[i++];
        } else {
            merged[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        merged[k++] = nums[i++];
    }

    while (j <= right) {
        merged[k++] = nums[j++];
    }

    for (int p = 0; p < merged.size(); p++) {
        nums[left + p] = merged[p];
    }

    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

    
};