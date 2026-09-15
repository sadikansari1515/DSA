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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;

        // Calculate length
        ListNode* cur = head;

        while (cur != nullptr) {
            cur = cur->next;
            len = len + 1;
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        int jumps = len - n;

        ListNode* prev = dummy;

        while (jumps > 0) {
            prev = prev->next;
            jumps = jumps - 1;
        }

        // Remove node
        prev->next = prev->next->next;

        return dummy->next;
    }
};