class Solution {
public:
    
  
   
int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    queue<pair<TreeNode*, unsigned long long>> q; // Using unsigned long long to prevent overflow
    
    q.push(make_pair(root, 1));
    int maxWidth = 0;
    
    while (!q.empty()) {
        int size = q.size();
        unsigned long long left = q.front().second;
        unsigned long long right = left;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            right = q.front().second;
            q.pop();
            
            if (node->left) {
                q.push(make_pair(node->left, right * 2));
            }
            
            if (node->right) {
                q.push(make_pair(node->right, right * 2 + 1));
            }
        }
        
        maxWidth = max(maxWidth, static_cast<int>(right - left + 1));
    }
    
    return maxWidth;
}
};