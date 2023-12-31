#include <bits/stdc++.h> 
int floorInBST(TreeNode<int> * root, int X)
{
    // inorder traversal
    // Recursive Approach
    // Base Case
    if(root == NULL) return -1;
    int left = floorInBST(root->left, X);
    if(root->val > X) return left;
    int right = floorInBST(root->right, X);
    return max(root->val, right);
}