/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    map<Node*, Node*> created;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (created.find(node) != created.end()) {
            return created[node];
        }
        Node* copy = new Node(node->val);
        created[node] = copy;
        vector<Node*> copiedNeighbors;
        for (auto neighbor : node->neighbors) {
            // if (created.find(neighbor) != created.end()) {
            //     copiedNeighbors.push_back(created[neighbor]);
            //     // continue;
            // } else {
            //     Node* copiedNeighbor = new Node(neighbor->val);
            //     created[neighbor] = copiedNeighbor;
            //     copiedNeighbors.push_back(cloneGraph(neighbor));
            // }
            copiedNeighbors.push_back(cloneGraph(neighbor));
        }
        copy->neighbors = copiedNeighbors;
        return copy;
    }
};
