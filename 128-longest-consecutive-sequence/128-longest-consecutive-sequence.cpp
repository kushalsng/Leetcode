class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto x: nums)s.insert(x);
        int n = s.size();
        if(n <2)return n;
        auto i=s.begin();
        
        auto j = i;
        j++;
        int val=1,ans=1;
        while(j!=s.end()){
            // cout<<*i<<" "<<*j<<" ";
            if(*j - *i !=1){
                ans = max(ans,val);
                val = 1;
            }else val++;
            i++;j++;
        }
        ans = max(ans,val);
        return ans;
    }
};