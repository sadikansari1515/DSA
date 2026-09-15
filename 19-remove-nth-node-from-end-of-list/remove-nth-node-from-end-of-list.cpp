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
        int currJumps = n;


        // Calculate length
        ListNode* cur = head;

        while (currJumps > 0) {
            cur = cur->next;
            currJumps--;
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (cur != nullptr) {
            prev = prev->next;
            cur = cur->next;
        }

        // Remove node
        prev->next = prev->next->next;

        return dummy->next;
    }
};