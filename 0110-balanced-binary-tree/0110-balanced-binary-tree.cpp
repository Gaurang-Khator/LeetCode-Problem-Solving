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
    int helper(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return max(helper(root->left), helper(root->right))+1;

    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        int lh = helper(root->left);
        int rh = helper(root->right);
        if(abs(lh-rh) <= 1 && isBalanced(root->left)==true && isBalanced(root->right)==true) {
            return true;
        }
        return false;
    }
};