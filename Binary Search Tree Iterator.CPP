class BSTIterator {


private:
    stack<TreeNode*> nodes;
    
    void pushAllLeft(TreeNode* root) {
        while (root != nullptr) {
            nodes.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = nodes.top();
        nodes.pop();
        pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};