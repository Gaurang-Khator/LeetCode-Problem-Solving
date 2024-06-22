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
    bool helper(TreeNode* left, TreeNode* right) {
        if(left==NULL && right==NULL) {
            return true;
        }
        if(left==NULL || right==NULL) {
            return false;
        }
        bool t1 = helper(left->left, right->right);
        bool t2 = helper(left->right, right->left);
        if(left->val == right->val && t1==true && t2==true) {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        return helper(root->left, root->right);
    }
};