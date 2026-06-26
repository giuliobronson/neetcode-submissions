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
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node* head = new Node(node->val); visited[node] = head;

        for (auto& neighbor : node->neighbors) {
            if (visited.count(neighbor)) {
                head->neighbors.push_back(visited[neighbor]);
            }
            else {
                head->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return head;
    }
};
