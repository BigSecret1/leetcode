class MyCircularQueue {
public:
    vector<int> v;
    int l, r;
    int sz = 0;
    MyCircularQueue(int k) {
        sz = k;
        v.resize(3004, 0);
        l = -1, r = -1;
    }
    
    bool enQueue(int value) {
        if(r - l + 1 >= sz && l != -1) return false;
        v[r + 1] = value;
        r++;
        if(l == -1) l = 0;
        return true;
    }
    
    bool deQueue() {
        if(l > r) return false;
        l++;
        return true;
    }
    
    int Front() {
        if(l < 0 || l > r) return -1;
        return v[l];
    }
    
    int Rear() {
        if(r == -1 || l > r) return -1;
        return v[r];
    }
    
    bool isEmpty() {
        if(l > r || l == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(r - l + 1 == sz) return true;
        return false;
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
