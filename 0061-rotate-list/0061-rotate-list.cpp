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
        int len = 0;
        while(head!=nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) {
            return head;
        }
        int len = length(head);
        k = k%len;
        for(int i=0; i<k; i++) {
            ListNode* temp = head;
            while(temp->next->next!=NULL) {
                temp = temp->next;
            }
            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }
        return head;
    }
};