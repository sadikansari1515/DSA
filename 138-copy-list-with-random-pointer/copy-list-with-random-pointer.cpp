/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        Node* curr = head;

        while(curr) {
            Node* node = new Node(curr->val);
            Node* currNext = curr->next;
            node->next = currNext;
            curr->next = node;
            curr = currNext;
        }

        curr = head;

        while(curr) {
            Node* newNode = curr->next;
            newNode->random = curr->random!=nullptr? curr->random->next: nullptr;
            curr = curr->next->next;
        }

        Node* oldHead = head;
        Node* newHead = head->next;
        Node* resultHead = head->next;

        while(oldHead != nullptr) {
            oldHead->next = newHead->next;
            oldHead = oldHead->next;
            newHead->next = oldHead != nullptr ? oldHead->next : nullptr;
            newHead = newHead->next;
        }

        return resultHead;
    }
};