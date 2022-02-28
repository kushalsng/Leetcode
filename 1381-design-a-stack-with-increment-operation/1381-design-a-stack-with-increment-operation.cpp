class CustomStack {
public:
    int *arr;
    int top;
    int n;
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        top=-1;
        n=maxSize;
    }
    
    void push(int x) {
        if(top< n-1){
            top++;
            arr[top]=x;
        }
    }
    
    int pop() {
        int save= -1;
        if(top>=0){
            save=arr[top];
            top--;
        }
        return save;
    }
    
    void increment(int k, int val) {
        int i=0;
        if(k>= top+1){
            while(i<=top){
                arr[i] += val;
                i++;
            }
        }else {
            
            while(i<k){
                arr[i] += val;
                i++;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */