struct MinStackNode {
    int value;
    int prevMinValue;
    MinStackNode *prev;

    MinStackNode(int value=0, int prev_min_value=0, MinStackNode *prev=nullptr) {
        this->value = value;
        this->prevMinValue = prev_min_value;
        this->prev = prev;
    }
};


class MinStack {
private:
    int min;
    MinStackNode *topNode;
public:
    MinStack() {
        this->min = -1*__INT32_MAX__;
        this->topNode = nullptr;
    }
    
    void push(int val) {
        if (this->topNode == nullptr) {
            this->topNode = new MinStackNode(val, -1*__INT32_MAX__, nullptr);
            this->min = val;
        } else {
            MinStackNode *temp = new MinStackNode(val, this->min, this->topNode);
            this->topNode = temp;
            if (val < this->min) {
                this->min = val;
            }
        }
    }
    
    void pop() {
        if (this->topNode == nullptr) {
            return;
        } else {
            MinStackNode *prev_top = this->topNode;
            this->topNode = prev_top->prev;
            this->min = prev_top->prevMinValue;
            delete(prev_top);
        }
    }
    
    int top() {
        if (this->topNode == nullptr) {
            return -1;
        } else {
            return this->topNode->value;
        }
    }
    
    int getMin() {
        return this->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */