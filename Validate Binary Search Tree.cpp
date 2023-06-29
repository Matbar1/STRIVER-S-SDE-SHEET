class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (root == nullptr)
        return true;
    
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}
};