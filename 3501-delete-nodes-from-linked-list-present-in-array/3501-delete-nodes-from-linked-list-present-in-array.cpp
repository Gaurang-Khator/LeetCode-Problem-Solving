/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* t = new ListNode(-1);
        t->next = head;
        ListNode* temp = t;
        while(temp->next != nullptr) {
            if(s.find(temp->next->val) != s.end()) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return t->next;
    }
};