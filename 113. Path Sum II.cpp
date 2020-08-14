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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        
        if(root == NULL) return ret;
        
        if(root->left == NULL && root->right == NULL && root->val == sum) {
            vector<int> temp = {sum};
            ret.push_back(temp);
            return ret;
        }
        
        int val = root->val;
        vector<vector<int> > leftvec = pathSum(root->left, sum - val);
        vector<vector<int> > rightvec = pathSum(root->right, sum - val);
        
        if(leftvec.size()) {
            for(auto x : leftvec) {
                vector<int> tobepushed = {val};
                tobepushed.insert(tobepushed.end(), x.begin(), x.end());
                ret.push_back(tobepushed);
            }
        }
        
        if(rightvec.size()) {
            for(auto x : rightvec) {
                vector<int> tobepushed = {val};
                tobepushed.insert(tobepushed.end(), x.begin(), x.end());
                ret.push_back(tobepushed);
            }
        }
        
        return ret;
    }
};