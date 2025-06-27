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
        if(root == nullptr) return 0;
        int res = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int s = q.size();
            long long first = q.front().second; //minm of level
            long long last = q.back().second; //maxm of level
            // res = max(res, last-first+1);
            if(res < last-first+1) res = last-first+1;
            for(int i=0; i<s; i++) {
                TreeNode* temp = q.front().first;
                long long idx = q.front().second - first;
                q.pop();
                if(temp->left) q.push({temp->left, idx*2+1});
                if(temp->right) q.push({temp->right, idx*2+2});
            }
        }
        return res;
    }
};