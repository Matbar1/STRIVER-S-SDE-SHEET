class Solution {
public:
int kthSmallest(TreeNode* root, int k) {
    int count = countNodes(root->left);
    
    if (k <= count)
        return kthSmallest(root->left, k);
    else if (k > count + 1)
        return kthSmallest(root->right, k - count - 1);
    
    return root->val;
}

int countNodes(TreeNode* node) {
    if (node == nullptr)
        return 0;
    
    return 1 + countNodes(node->left) + countNodes(node->right);
} 

    
};