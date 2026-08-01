/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        // we return an empty vector in case of null root, or when there is no node
        if (!root) return {};

        vector<int> v;

        for (int i=0; i<root->children.size(); i++) {
            vector<int>v1 = postorder(root->children[i]);
            v.insert(v.end(), v1.begin(), v1.end());
        }
        v.push_back(root->val);

        return v;
    }
};