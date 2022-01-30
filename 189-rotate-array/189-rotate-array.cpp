class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        long long n = nums.size();
        k = k% n;
        vector<int> v(n-k);
        for(int i =0; i< v.size(); i++){
            v[i] = nums[i];
        }
        int ind = 0;
        for(int i = n-k; i<n; i++){
            nums[ind] = nums[i];
            ind++;
        }
        for(int i = k; i<nums.size(); i++){
            nums[i] = v[i-k];
        }
    }
};