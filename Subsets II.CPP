class Solution {
public:
  void backtrack(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int start) {
    result.push_back(subset);

    for (int i = start; i < nums.size(); i++) {
        // Skip duplicates
        if (i > start && nums[i] == nums[i - 1])
            continue;

        subset.push_back(nums[i]);
        backtrack(result, subset, nums, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    sort(nums.begin(), nums.end());  // Sort the input to handle duplicates

    backtrack(result, subset, nums, 0);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsets = subsetsWithDup(nums);

    // Print the subsets
    for (const auto& subset : subsets) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
};
//This solution uses backtracking to generate all subsets of the given input array while handling duplicates. The subsetsWithDup function takes the input vector nums and returns a 2D vector result containing all the subsets. The main function demonstrates the usage by printing the subsets f??or the input [1, 2, 2].

//Remember to include the necessary headers (iostream, vector, algorithm) and use the std namespace if d
};