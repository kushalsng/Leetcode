class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> fx, tail;
        for(int &i:nums)fx[i]++;
        for(int &i: nums){
            if(fx[i]<=0)continue;
            fx[i]--;
            if(tail[i-1]>0){
                tail[i-1]--;
                tail[i]++;
            }else if(fx[i+1] && fx[i+2]){
                fx[i+1]--;
                fx[i+2]--;
                tail[i+2]++;
            }else return false;
        }
        return true;
    }
};