class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        priority_queue<pair<long double,vector<int>>, vector<pair<long double,vector<int>>>, greater<pair<long double,vector<int>>>> pq;
        
        for(auto p: pts){
            long double val = sqrt(p[0]*p[0] + p[1] * p[1]);
            pq.push({val, p});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};