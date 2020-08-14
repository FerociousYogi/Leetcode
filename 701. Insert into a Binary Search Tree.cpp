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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* insert = new TreeNode(val);
        
        if(!root) {
            root = insert;
            return root;
        }
        
        TreeNode* ptr = root;
        TreeNode* lastptr;
        
        while(ptr) {
            lastptr = ptr;
            if(ptr->val < val) {
                ptr = ptr->right;
            }
            else {
                ptr = ptr->left;
            }
        }
        
        if(lastptr->val < val) {
            lastptr->right = insert;
        }
        else {
            lastptr->left = insert;
        }
        
        return root;
    }
};


// Recursive implementation: 


	TreeNode* insertIntoBST(TreeNode *node, int val) {
		if (!node) {
			TreeNode *newNode = new TreeNode(val);
			return newNode;
		}
		if (val < node->val) {
			node->left = insertIntoBST(node->left, val);
		}
		else {
			node->right = insertIntoBST(node->right, val);
		}
		return node;
	}