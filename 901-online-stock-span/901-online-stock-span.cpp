class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    int last = -1;
    StockSpanner() {
    }
    
    int next(int price) {
        v.push_back(price);
        last++;
        if(v.size() == 1) return 1;
        if(v[last] >= v[last -1]){
            while(!s.empty() && v[last] >= v[s.top()]) s.pop();
            if(!s.empty()) return abs(s.top() - last);
            else return last+1;
        }
        s.push(last-1);
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */