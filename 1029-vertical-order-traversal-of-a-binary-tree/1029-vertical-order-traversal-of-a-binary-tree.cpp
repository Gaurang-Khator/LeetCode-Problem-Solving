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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mp;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                auto p = q.front();
                q.pop();
                TreeNode* temp = p.first;
                int vert = p.second.first;
                int lev = p.second.second;
                mp[vert][lev].insert(temp->val); 
                if(temp->left) {
                    q.push({temp->left, {vert-1, lev+1}});
                }
                if(temp->right) {
                    q.push({temp->right, {vert+1, lev+1}});
                }
            }
        }
        for(auto i: mp) {
            vector<int> temp;
            for(auto j: i.second) {
                auto ms = j.second;
                temp.insert(temp.end(), ms.begin(), ms.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};