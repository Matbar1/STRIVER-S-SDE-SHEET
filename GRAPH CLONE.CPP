class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* clonedNode = new Node(node->val);
        visited[node] = clonedNode;

        for (Node* neighbor : node->neighbors) {
            clonedNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return clonedNode;
    }
};