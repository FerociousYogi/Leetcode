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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        if(inorder.size() == 0) return root;
        if(inorder.size() == 1) {
            root = new TreeNode(preorder[0]);
            return root;
        }
        
        root = new TreeNode(preorder[0]);
        
        vector<int>::iterator ptr = find(inorder.begin(), inorder.end(), preorder[0]);
        int distance = ptr - inorder.begin();
        
        vector<int> inorder_left(inorder.begin(), ptr);
        vector<int> inorder_right(ptr + 1, inorder.end());
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + distance);
        vector<int> preorder_right(preorder.begin() + 1 + distance, preorder.end());
        
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        
        return root;
    }
};