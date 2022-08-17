class Solution {
public:
    int merge(vector<int>& nums, int l, int mid, int r){
        int i,j,k,cnt=0;
        j=mid+1;
        for(int i=l; i<=mid; i++){
            while(j<=r && nums[i] >(long) 2*nums[j])j++;
            cnt += (j - mid-1);
        }
        
        vector<int> aux;
        i=l, j=mid+1;
        while(i<=mid && j<=r){
            // if(nums[i]> 2*nums[j])cnt++;
            if(nums[i]<=nums[j])aux.push_back(nums[i++]);
            else aux.push_back(nums[j++]);
            
        }
        while(i<=mid)aux.push_back(nums[i++]);
        while(j<=r)aux.push_back(nums[j++]);
        
        for(int ind=l; ind<=r; ind++)nums[ind] = aux[ind - l];
        return cnt;
    }
    int mergesort(vector<int>& nums,int l, int r){
        if(l>=r)return 0;
        int mid = l + (r-l)/2;
            int val = mergesort(nums, l, mid);
            val += mergesort(nums, mid+1, r);
            val += merge(nums,l,mid,r);
        return val;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};