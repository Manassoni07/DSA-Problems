/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int,TreeNode*> Depth_Parent(TreeNode* root,int x,int depth){
        if(!root) return {-1 , nullptr};

        if(root->left && root->left->val == x) {
            return {depth + 1 , root};
        } 
        if(root->right && root->right->val == x) {
            return {depth + 1 , root};
        } 
        
        pair<int,TreeNode*> left = Depth_Parent(root->left,x,depth+1);
        if(left.second) return left;
        pair<int,TreeNode*> right = Depth_Parent(root->right,x,depth+1);
        if(right.second) return right;

        return { -1 , nullptr };
    }
    bool isCousins(TreeNode* root, int x, int y) {
        // recursively get depth and parent of the node
        pair<int,TreeNode*> nodeX = Depth_Parent(root,x,0); 
        pair<int,TreeNode*> nodeY = Depth_Parent(root,y,0);

        if(nodeX.first == nodeY.first && nodeX.second != nodeY.second) return true;
        return false;
    }
};