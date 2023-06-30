class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (p->val < root->val && q->val < root->val) {
            // Both nodes are in the left subtree
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            // Both nodes are in the right subtree
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // Nodes are in different subtrees or one of the nodes is the current root
            return root;
        }
    }
};