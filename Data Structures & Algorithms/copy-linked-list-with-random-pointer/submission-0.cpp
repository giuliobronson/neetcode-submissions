/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> nodes;

    Node* copyNode(Node* node) {
        if (!node) return nullptr;
        if (nodes.count(node)) return nodes[node];
        Node* newNode = new Node(node->val); nodes[node] = newNode;
        newNode->next = copyNode(node->next);
        newNode->random = copyNode(node->random);
        return newNode;
    }

public:
    Node* copyRandomList(Node* head) {
        return copyNode(head);
    }
};
