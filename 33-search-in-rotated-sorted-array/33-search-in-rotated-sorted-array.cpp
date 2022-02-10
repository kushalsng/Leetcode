class Solution {
public:
    int searchHelp(int l, int r, int target, vector<int> nums){
        if(l<=r){
            int mid = l + (r-l)/2;
            // cout<<mid<<" ";

            if(nums[mid] == target) return mid;
            
            if(nums[mid]< target) return searchHelp(mid+1, r, target, nums);
            
            return searchHelp(l, mid -1, target, nums);
        }
            
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l =0, r=nums.size() -1;
        int me = -1;
        
        while(l<=r){
            // cout<<"l= "<<l<<", r= "<<r<<", mid= "<<mid<<", prev= "<<prev<<", next= "<<next<<endl;
            int mid = l + (r-l)/2;
            // cout<<mid<<" ";
            int next = (mid+1) % nums.size();
            int prev = (mid - 1 + nums.size())% nums.size();
            // cout<<"l= "<<l<<", r= "<<r<<", mid= "<<mid<<", prev= "<<prev<<", next= "<<next<<endl;

            if(nums[mid]<nums[prev] && nums[mid] < nums[next]){
                me= mid; break;
            }
            else if(nums[mid]<nums[0]){
                r= mid -1;
            }else {
                l = mid +1;
            }
        }
        // cout<<me<<" ";
        if(me != -1 && nums[me] == target) return me;
        return max(searchHelp(0, me -1, target, nums),searchHelp(me+1, nums.size() - 1, target, nums));

        return -1;
    }
};