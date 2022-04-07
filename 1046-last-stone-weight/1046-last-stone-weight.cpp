class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
        priority_queue<int> pq;
        for(auto x:st)pq.push(x);
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x!=y)pq.push(abs(x-y));
        }
        return pq.size() ? pq.top() : 0;
    }
};