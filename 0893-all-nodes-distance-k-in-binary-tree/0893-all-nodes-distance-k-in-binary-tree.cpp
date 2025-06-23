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
    void parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        parents(root, mp);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        while(!q.empty()) {
            int s = q.size();
            if(k == 0) break;
            for(int i=0; i<s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && visited[temp->left] != true) {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && visited[temp->right] != true) {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(mp[temp] && visited[mp[temp]] != true) {
                    q.push(mp[temp]);
                    visited[mp[temp]] = true;
                }
            }
            k--;
        }
        vector<int> res;
        while(q.empty() == false) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};