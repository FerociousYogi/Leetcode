/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) {
            return NULL;
        }
        
        int rootval = preorder[0];
        vector<int> left, right;
        
        if(preorder.size() == 1) {
            TreeNode* root = new TreeNode(rootval);
            return root;
        }
        
        int ptr = 1;
        while(ptr < preorder.size() && preorder[ptr] < rootval) {
            left.push_back(preorder[ptr++]);
        }
        
        while(ptr < preorder.size()) {
            right.push_back(preorder[ptr++]);
        }
        
        TreeNode* root = new TreeNode(rootval);
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        
        return root;
    }
};