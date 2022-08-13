class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int i=1,j=n;
        int active = 1;
        while(k){
            ans.push_back(i++);
            k--;
            if(k)ans.push_back(j--),k--;
        }
        if(i == j)ans.push_back(j);
        else{
            if(ans.back() == i-1){
                while(i<=j){
                    ans.push_back(i++);
                }
            }else if(ans.back() == j+1){
                while(j>=i)ans.push_back(j--);
            }
        }
        return ans;
    }
};