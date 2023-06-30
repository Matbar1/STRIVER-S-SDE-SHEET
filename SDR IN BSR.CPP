class Codec {
public:
 string serialize(TreeNode* root) {
        if (root == NULL)
            return "null";

        string serialized;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                serialized += "null ";
                continue;
            }

            serialized += to_string(curr->val) + " ";
            q.push(curr->left);
            q.push(curr->right);
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null")
            return NULL;

        istringstream iss(data);
        string val;
        iss >> val;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!(iss >> val))
                break;

            if (val != "null") {
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);
            }

            if (!(iss >> val))
                break;

            if (val != "null") {
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }

        return root;
    }
};

// Helper function to print the binary tree for testing
void printTree(TreeNode* root) {
    if (root == NULL) {
        cout << "null ";
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));