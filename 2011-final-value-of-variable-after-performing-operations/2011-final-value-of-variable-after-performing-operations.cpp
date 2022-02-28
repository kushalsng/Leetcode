class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto str: operations) str[1] == '+' ? ans++ : ans--;
        return ans;
    }
};