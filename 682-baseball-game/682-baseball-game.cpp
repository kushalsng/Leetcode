class Solution {
public:
    
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(string s: ops){
            int  n=v.size();
            if(s == "+"){
                v.push_back(v[n-1]+v[n-2]);
            }
            else if(s == "D"){
                v.push_back(v[n-1]*2);
            }else if(s == "C")v.pop_back();
            else{
                v.push_back(stoi(s));
            }
        }
        int ans=0;
        for(auto x: v)ans+= x;
        return ans;
    }
};