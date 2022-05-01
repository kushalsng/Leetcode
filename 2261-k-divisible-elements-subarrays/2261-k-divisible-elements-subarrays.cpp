class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n= nums.size();
        unordered_set<string> us;
        for(int i=0; i<n;i++){
            for(int len = i; len<n; len++){
                int cnt=0;
                string temp = "";
                for(int j=i; j<=len;j++){
                    temp.push_back(nums[j]);
                    if(nums[j]%p ==0)cnt++;
                }
                if(cnt<=k and !temp.empty())us.insert(temp);
            }
        }
        return size(us);
    }
};