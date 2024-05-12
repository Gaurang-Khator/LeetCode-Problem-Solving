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
    int length(ListNode* head) {
        int count = 0;
        if(head==NULL) {
            return 0;
        }
        ListNode* temp = head;
        while(temp != nullptr ) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt;
        int len = length(head);
        int count = 0;
        while(curr != nullptr && count<k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count ++;
        }
        if(nxt != NULL && k <= len-k) {
            head->next = reverseKGroup(nxt, k);
        } else {
            head->next = nxt;
        }
        return prev;
    }
};