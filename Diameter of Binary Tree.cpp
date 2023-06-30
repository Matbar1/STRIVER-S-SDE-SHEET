class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }

private:
    int maxDepth(TreeNode* node, int& diameter) {
        if (node == NULL) {
            return 0;
        }

        int leftHeight = maxDepth(node->left, diameter);
        int rightHeight = maxDepth(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }
};