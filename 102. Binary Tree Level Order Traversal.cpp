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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        
        if(root == NULL) return ret;
        
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        while(nodes.size()) {
            vector<int> tobepushed;
            vector<TreeNode*> children;
            for(auto x : nodes) {
                tobepushed.push_back(x->val);
                if(x->left) children.push_back(x->left);
                if(x->right) children.push_back(x->right);
            }
            ret.push_back(tobepushed);
            nodes = children;
            
        }
        
        return ret;
    }
};