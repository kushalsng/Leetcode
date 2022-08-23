class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        if(n<4)return ans;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum == target){
                        vector<int> v{nums[i],nums[j],nums[k],nums[l]};
                        s.insert(v);
                        k++,l--;
                    }else if(sum < target)k++;
                    else l--;
                }
            }
        }
        for(auto it = s.begin(); it != s.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};