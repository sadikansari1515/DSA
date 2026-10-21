
class MinNode {
public:
    int min;
    int count;

    MinNode(int m, int c) {
        this->min = m;
        this->count = c;
    }
};

class MinStack {
public:
    stack<int> s;
    stack<MinNode> minStack;

    MinStack() {
        
    }

    void push(int val) {
        s.push(val);

        if (minStack.empty()) {
            minStack.push(MinNode(val, 1));
            return;
        }

        MinNode& minTop = minStack.top();

        if (val == minTop.min) {
            minTop.count++;
        } 
        else if (val < minTop.min) {
            minStack.push(MinNode(val, 1));
        }
    }

    void pop() {
        if (s.empty()) {
            return;
        }

        int val = s.top();
        s.pop();

        MinNode& minTop = minStack.top();

        if (val == minTop.min) {
            if (minTop.count == 1) {
                minStack.pop();
            } 
            else {
                minTop.count--;
            }
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        return s.top();
    }

    int getMin() {
        if (minStack.empty()) {
            return -1;
        }

        return minStack.top().min;
    }
};
