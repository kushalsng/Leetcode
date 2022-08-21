class Solution {
public:
    int minNumberOfHours(int ien, int iex, vector<int>& en, vector<int>& ex) {
        int sum=0,n = en.size();
        int mx1;
        for(auto x: en)sum += x;
        // cout<<sum<<" ";
        int ans = 0;
        if(sum>=ien) ans += abs(sum - ien)+1;
        
        for(auto x: ex){
            if(x>=iex){
                ans += abs(iex-x)+1;
                iex += abs(iex-x)+1;
                
                
            }
            iex += x;
        }
        return ans;
    }
};