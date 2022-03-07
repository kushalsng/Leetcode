class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
        stack<int> s;
        for(int i=0; i<h.size(); i++){
            while(!s.empty() && h[s.top()] >= h[i]) {
                int tp = s.top();
                s.pop();
                int res = h[tp] * (s.empty() ? i : (i - s.top() -1));
                ans = max(ans, res);
            }
            s.push(i);
        }
        while(!s.empty()){
            int tp = s.top();
            s.pop();
            int res = h[tp] * (s.empty() ? h.size(): (h.size() - s.top() -1));
            ans = max(ans, res);
        }
        return ans;
    }
};