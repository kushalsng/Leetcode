class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i= 0; i< nums1.size(); i++){
            vector<int>::iterator it = find(nums2.begin(), nums2.end(), nums1[i]);
            int init_size = ans.size();
            for(auto j = it; j< nums2.end(); j++){
                if(*(j) > nums1[i]) {
                    ans.push_back(*(j));
                    break;
                }
            }
            if(ans.size() == init_size) ans.push_back(-1);
            
        }
        return ans;
    }
};