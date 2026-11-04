class Node {
public:
    int val;
    Node* next;
    Node(int val, Node* next) {
        this->val = val;
        this->next = next;
    }
};
class MyCircularQueue {
public:
    Node* head;
    Node* tail;
    int count;
    int maxSize;
    MyCircularQueue(int k) {
        head = nullptr;
        tail = nullptr;
        maxSize = k;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }

        Node* node = new Node(value, nullptr);
        if(count == 0) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        Node* temp = head;
        head = head->next;
        count--;
        delete temp;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }

        return head->val;
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }

        return tail->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */