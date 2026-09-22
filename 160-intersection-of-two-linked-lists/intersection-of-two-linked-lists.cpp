/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0,
            lenB = 0;
        ListNode* currA = headA;        
        ListNode* currB = headB;        
        while(currA) {
            currA = currA->next;
            lenA++;
        }
        while(currB) {
            currB = currB->next;
            lenB++;
        }
        currA = headA;
        currB = headB;
        int diff = abs(lenA - lenB);
        if(lenA > lenB) {
            int i = 0;
            while(i < diff) {
                currA = currA->next;
                i++;
            }
        }
        else {
            int i = 0;
            while(i < diff) {
                currB = currB->next;
                i++;
            }
        }
        while(currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }
        return currA;
    }
};