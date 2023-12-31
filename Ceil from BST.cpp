#include <bits/stdc++.h> 
 int findCeil(BinaryTreeNode<int> *root, int X){
    // inorder traversal
    // Iterative Approach
    int ans = -1;
    bool flag = true;
    BinaryTreeNode<int>* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            if((curr->data >= X) && flag) {
                ans = curr->data;
                flag = false;
            }
            curr = curr->right;
        }
        else{
            BinaryTreeNode<int>* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                if((curr->data >= X) && flag) {
                    ans = curr->data;
                    flag = false;
                }
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}