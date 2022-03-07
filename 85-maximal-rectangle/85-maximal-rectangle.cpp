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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int ans=0;
        vector<int> arr(c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] != '0') ++arr[j];
                else arr[j] = 0;
            }
            ans = max(ans, largestRectangleArea(arr));
        }
        return ans;
    }
};