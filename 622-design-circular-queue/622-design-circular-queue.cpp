class MyCircularQueue {
public:
    int *a;
    int cap,size,f;
    MyCircularQueue(int k) {
        cap = k;
        size = 0, f=0;
        a = new int[k];
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        int r = f + size;
        a[r % cap] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        ++f;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return a[f % cap];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return a[(f + size-1) % cap];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

//["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
//[[3],[1],[2],[3],[4],[],[],[],[4],[]]
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