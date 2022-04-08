class KthLargest {
public:
    priority_queue<int> mxh;
    priority_queue<int, vector<int>, greater<int>> mnh;
    int kay;
    KthLargest(int k, vector<int>& nums) {
        kay=k;
        if(nums.size()!=0){
            for(int x: nums)mxh.push(x);
            while(!mxh.empty() && k--){
                mnh.push(mxh.top());
                mxh.pop();
            }
        }
    }
    
    int add(int val) {
        
        if(mnh.size()<kay) mnh.push(val);
        // else if(val<mnh.top()) mxh.push(val);
        else if(val>=mnh.top()){
            // int x = mnh.top();
            mnh.pop();
            // mxh.push(x);
            mnh.push(val);
        }
        return mnh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */