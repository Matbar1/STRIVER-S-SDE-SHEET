/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
     
    int kthLargest(Node *root, int &k)
    {
        if(!root) return -1;

        int a = kthLargest(root->right, k);
        k--;
        if(k==0) return root->data;
        int b = kthLargest(root->left, k);

        return a==-1 ? b : a;
    }
};