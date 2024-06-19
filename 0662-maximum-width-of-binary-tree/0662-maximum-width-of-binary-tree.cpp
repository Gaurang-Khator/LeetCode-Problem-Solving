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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int width = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(q.empty() == false) {
            int s = q.size();
            int min = q.front().second;
            int start, end;

            for(int i=0; i<s; i++) {
                TreeNode* node = q.front().first;
                long long x = q.front().second - min;
                q.pop();
                if(i == 0) {
                    start = x;
                }
                if(i == s-1) {
                    end = x;
                }

                if(node->left != nullptr) {
                    q.push({node->left, x*2+1});
                }
                if(node->right != nullptr) {
                    q.push({node->right, x*2+2});
                }
            }
            width = max(width, end-start+1);
        }
        return width;
    }
};