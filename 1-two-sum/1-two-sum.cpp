class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        vector<pair<int, int>> aux;
        for(int i=0;i<nums.size(); i++){
            aux.push_back({nums[i], i});
        }
        sort(aux.begin(), aux.end());
        int i=0, j= nums.size()-1;
        
        while(i<j){
            if(aux[i].first + aux[j].first == target){
                v.push_back(aux[i].second);
                v.push_back(aux[j].second);
                return v;
            } else if(aux[i].first + aux[j].first > target) j--;
            else i++;
        }
        return v;
    }
};