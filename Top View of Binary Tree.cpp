Bobble BackgroundBobble Head
Problems
Courses
Geek-O-Lympics
Events
POTD

Refresh

Time (IST)	Status	Lang	Test Cases	Code
2023-06-06 11:36:28	Correct	cpp	106 / 106	View
C++ (g++ 5.4)
Average Time: 45m



  

Custom Input
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};