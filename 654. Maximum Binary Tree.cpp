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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) {
            return NULL;
        }
        
        vector<int>::iterator data = max_element(nums.begin(), nums.end());
        int value = *data;
        
        vector<int> left(nums.begin(), data);
        vector<int> right(data + 1, nums.end());
        
        TreeNode* root = new TreeNode(value);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        
        return root;
    }
};