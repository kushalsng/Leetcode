class Solution {
public:
    void solve(int n, int k, string &s, vector<int> &ans){
        if(n == 0){
            long long t = stoll(s);
            if(ans.empty() || t != ans.back())
                ans.push_back(t);
            return;
        }
        
        if(s.back() - k >= '0'){
            s += s.back()-k;
            solve(n-1, k,s,ans);
            s.pop_back();
        }
        if(s.back() + k <='9'){
            s += s.back() +k;
            solve(n-1,k,s,ans);
            s.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            string s = to_string(i);
            solve(n-1,k,s,ans);
        }
        return ans;
    }
};