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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);

        while(curr != nullptr) {
            ListNode* p = dummy;
            ListNode* c = dummy->next;

            while(c != nullptr && c->val <= curr->val) {
                p = p->next;
                c = c->next;
            }
            ListNode* next = curr->next;
            curr->next = c;
            p->next = curr;
            curr = next;
        }
        return dummy->next;
    }
};