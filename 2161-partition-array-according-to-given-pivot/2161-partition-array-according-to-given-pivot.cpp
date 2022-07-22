class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> copy;
        for(auto x: nums){
            if(x<pivot)copy.push_back(x);
        }
        for(auto x: nums){
            if(x==pivot)copy.push_back(x);
        }
        for(auto x: nums){
            if(x>pivot)copy.push_back(x);
        }
        return copy;
    }
};