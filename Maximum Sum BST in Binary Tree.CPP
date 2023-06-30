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
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        isBST(root, maxSum);
        return maxSum;
    }

private:
    struct Result {
        int minVal;
        int maxVal;
        int sum;
        bool isBST;
        Result(int minVal, int maxVal, int sum, bool isBST)
            : minVal(minVal), maxVal(maxVal), sum(sum), isBST(isBST) {}
    };

    Result isBST(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return Result(INT_MAX, INT_MIN, 0, true);
        }

        Result left = isBST(node->left, maxSum);
        Result right = isBST(node->right, maxSum);

        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            int sum = left.sum + right.sum + node->val;
            maxSum = max(maxSum, sum);
            return Result(min(node->val, left.minVal), max(node->val, right.maxVal), sum, true);
        } else {
            return Result(0, 0, 0, false);
        }
    }
};