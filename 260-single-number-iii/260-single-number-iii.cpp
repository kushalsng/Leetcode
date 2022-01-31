class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i: nums) xr ^= i;
        
        int ind=0;
        while((xr & (1<<ind)) == 0) ind++;
        
        int set=0, notset = 0;
        for(int i: nums){
            if((i & (1<<ind))) set ^= i;
            else notset ^= i;
        }
        vector<int> v{set, notset};
        return v;
    }
};