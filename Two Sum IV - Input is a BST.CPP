/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hashSet;
        return findTwoSum(root, k, hashSet);
    }

private:
    bool findTwoSum(TreeNode* node, int k, unordered_set<int>& hashSet) {
        if (node == nullptr) {
            return false;
        }
        
        int complement = k - node->val;
        
        if (hashSet.count(complement)) {
            return true;
        }
        
        hashSet.insert(node->val);
        
        return findTwoSum(node->left, k, hashSet) || findTwoSum(node->right, k, hashSet);
    }
};