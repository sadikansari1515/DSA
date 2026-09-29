/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;

        Node* pHead = new Node();
        Node* prev = pHead;

        stack<Node*> s;
        s.push(head);

        while(!s.empty()) {
            Node* curr = s.top();
            s.pop();

            curr->prev = prev;
            prev->next = curr;

            if(curr->next != nullptr) {
                s.push(curr->next);
            }

            if(curr->child != nullptr) {
                s.push(curr->child);
            }

            prev = curr;
            curr->child = nullptr;
        }

        pHead->next->prev = nullptr;
        return pHead->next;
    }
};