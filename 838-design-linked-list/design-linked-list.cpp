class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x) {
        val = x;
    }
};
class MyLinkedList {
public:
    int size;
    Node* head;
    Node* tail;
    MyLinkedList() {
        size = 0;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) {
            return -1;
        }
        
        if(index+1 < (size-index)) {
            Node* curr = head;
            int i = 0;
            while(i < index+1) {
                curr = curr->next;
                i++;
            }
            return curr->val;
        }
        else {
            Node* curr = tail;
            int i = 0;
            while(i < size-index) {
                curr = curr->prev;
                i++;
            }
            return curr->val;
        }
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) {
            return;
        }

        if(index < size-index) {
            Node* pred = head;
            int i = 0;
            while(i<index) {
                pred = pred->next;
                i++;
            }
            size++;
            Node* node = new Node(val);
            Node* succ = pred->next;

            node->next = succ;
            node->prev = pred;
            pred->next = node;
            succ->prev = node;
        }
        else {
            Node* succ = tail;
            int i = 0;
            while(i<size-index) {
                succ = succ->prev;
                i++;
            }
            size++;
            Node* node = new Node(val);
            Node* pred = succ->prev;

            node->next = succ;
            node->prev = pred;
            pred->next = node;
            succ->prev = node;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index >= size) {
            return;
        }
        if(index < size-index-1) {
            Node* pred = head;
            int i = 0;
            while(i<index) {
                pred = pred->next;
                i++;
            }
            Node* succ = pred->next->next;
            pred->next = succ;
            succ->prev = pred;
            size--;
        }
        else {
            Node* succ = tail;
            int i = 0;
            while(i<size-index-1) {
                succ = succ->prev;
                i++;
            }
            Node* pred = succ->prev->prev;
            pred->next = succ;
            succ->prev = pred;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */