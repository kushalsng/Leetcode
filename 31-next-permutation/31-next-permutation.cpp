class Solution {
public:
    void reverse(vector<int>& a,int i, int j){
        while(i<j) swap(a[i++],a[j--]);
    }
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int ind1=-1,ind2= -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind1 = i;
                break;
            }
        }
        if(ind1<0){
            reverse(nums, 0, n-1);
            return;
        }
        int temp=INT_MAX;
        for(int i=n-1; i> ind1; i--){
            if(nums[ind1] < nums[i]){
                if(nums[i]<temp){
                    temp = nums[i];
                    ind2 = i;
                }
            }
        }
        swap(nums[ind1], nums[ind2]);
        reverse(nums, ind1+1, n-1);
    }
};