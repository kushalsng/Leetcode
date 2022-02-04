class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        ll i=0,j=0,mx=0, n= nums.size();
        ll sum=0;
        for(int i: nums){
            sum += i;
        }
        ll k = sum - x;
        sum =0;
        if(k <0) return -1;
        if(k==0) return nums.size();
        
        while(j<nums.size()){
            sum += nums[j];
            if(sum < k) j++;
            else if(sum == k){
                mx = max(mx, j-i +1);
                j++;
            }else if(sum > k){
                while(sum > k){
                    sum -= nums[i];
                    i++;
                }
                if(sum == k) mx = max(mx, j-i+1);
                j++;
            }
        }
        
        if(mx == 0) return -1;
        return abs<ll>(mx - n);
    }
};