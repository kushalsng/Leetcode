class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size());
        stack<int> s;
        for(int i=t.size()-1; i>0; i--){
            if(t[i] > t[i-1]) {
                ans[i-1] = 1;
                s.push(i);
            }
            else{
                while(!s.empty() && t[s.top()]<= t[i-1]) s.pop();
                if(!s.empty())ans[i-1] = abs(s.top() - i) + 1;
            }
        }
        return ans;
    }
};