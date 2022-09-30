class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<rocks.size(); i++){
            pq.push(capacity[i] - rocks[i]);
        }
        int ans=0;
        while(additionalRocks>0 and !pq.empty()){
            if(additionalRocks>=pq.top())ans++;
            additionalRocks -= pq.top();
            pq.pop();
        }
        return ans;
    }
};