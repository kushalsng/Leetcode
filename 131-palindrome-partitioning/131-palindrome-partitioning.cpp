class Solution {
public:
    bool isPalindrome(string s, int i,int j){
        while(i<j) if(s[i++] !=s[j--]) return false;
        return true;
    }
    void solve(string s,int ind, vector<vector<string>> &ans, vector<string> &v){
        if(ind == s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s, 0,ans, v);
        return ans;
    }
};