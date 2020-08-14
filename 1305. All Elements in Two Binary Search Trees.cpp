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
    vector<int> preOrder(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) {
            return ret;
        }
        
        ret.push_back(root->val);
        
        vector<int> ret1 = preOrder(root->left);
        ret.insert(ret.end(), ret1.begin(), ret1.end());
        
        vector<int> ret2 = preOrder(root->right);
        ret.insert(ret.end(), ret2.begin(), ret2.end());
        
        return ret;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1 = preOrder(root1);
        vector<int> ret2 = preOrder(root2);
        
        ret1.insert(ret1.end(), ret2.begin(), ret2.end());
        
        sort(ret1.begin(), ret1.end());
        
        return ret1;
    }
};