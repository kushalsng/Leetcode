class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size() == k) return nums.size();
        int ct1=0,ct0=0;
        bool all0 = true, all1 = true;
        
        for(int i=0; i<nums.size(); i++){
            nums[i] ? ct1++ : ct0++;
            if(all0 && nums[i] == 1) all0 = false;
            if(all1 && nums[i] == 0) all1 = false;
        }
        if(all1 || ct0<=k) return nums.size();
        if(all0) return k;
        
        
        int i=0,j=0,mx=0;
        ct0= ct1=0;
        
        while(j<nums.size()){
            
            nums[j] ? ct1++ : ct0++;
            if(ct0 < k){
                j++;
            }else if(ct0 == k){
                mx = max(mx, ct0 + ct1);
                j++;
            }else if(ct0 > k){
                while(ct0 > k){
                    nums[i] ? ct1-- : ct0--;
                    i++;
                }
                if(ct0 == k)mx = max(mx, ct0 + ct1);
                j++;
            }
        }
        
        return mx;
    }
};