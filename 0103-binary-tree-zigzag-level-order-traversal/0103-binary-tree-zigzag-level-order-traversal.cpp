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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        deque<TreeNode*> dq;
        dq.push_front(root);
        bool reverse = false;

        while(!dq.empty()) {
            int s = dq.size();
            vector<int> level;
            for(int i=0; i<s; i++) {
                if(reverse == false) { //normal
                    TreeNode* temp = dq.front();
                    dq.pop_front();
                    if(temp->left) dq.push_back(temp->left);
                    if(temp->right) dq.push_back(temp->right);
                    level.push_back(temp->val);
                } else { //reverse
                    TreeNode* temp = dq.back();
                    dq.pop_back();
                    if(temp->right) dq.push_front(temp->right);
                    if(temp->left) dq.push_front(temp->left);
                    level.push_back(temp->val);
                }
            }
            reverse = !reverse;
            res.push_back(level);
        }
        return res;
    }
};