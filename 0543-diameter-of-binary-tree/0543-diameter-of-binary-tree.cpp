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
    int helper(TreeNode* root, int &dia) {
        if(root == nullptr) return 0;

        int leftHt = helper(root->left, dia);
        int rightHt = helper(root->right, dia);

        dia = max(dia, leftHt+rightHt);

        return max(leftHt, rightHt)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(root, dia);
        return dia;
    }
};