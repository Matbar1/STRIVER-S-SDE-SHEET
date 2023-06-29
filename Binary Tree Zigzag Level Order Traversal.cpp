class Solution {
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }
    
    queue<TreeNode*> queue;
    vector<vector<int>> result;
    int level = 0;
    
    queue.push(root);
    
    while (!queue.empty()) {
        int size = queue.size();
        vector<TreeNode*> levelNodes;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            levelNodes.push_back(node);
            
            if (node->left) {
                queue.push(node->left);
            }
            
            if (node->right) {
                queue.push(node->right);
            }
        }
        
        result.push_back({});
        
        for (int i = 0; i < size; i++) {
            result[level].push_back(level % 2 == 0 ? levelNodes[i]->val : levelNodes[size - 1 - i]->val);
        }
        
        level++;
    }
    
    return result;
}
};