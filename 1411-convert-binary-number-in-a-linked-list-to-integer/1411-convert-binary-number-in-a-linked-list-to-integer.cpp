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
    int getDecimalValue(ListNode* head) {
        string n = "";
        while(head != nullptr) {
            n = n + to_string(head->val);
            head = head->next;
        }
        int ans = 0;
        int i = 0;
        int j = n.size()-1;
        while(j >= 0) {
            if(n[j] == '1') {
                ans += (int)pow(2, i);
            }
            i++;
            j--;
        }
        return ans;
    }
};