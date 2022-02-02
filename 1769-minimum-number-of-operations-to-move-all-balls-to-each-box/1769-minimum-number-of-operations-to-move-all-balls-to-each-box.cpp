class Solution {
public:
    // int getBallDist(vector<int> ones,)
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        vector<int> ones;
        for(int i=0; i< boxes.size(); i++){
            if(boxes[i] == '1') ones.push_back(i);
        }
        for(int i=0; i<boxes.size(); i++){
            int moves=0;
            // unordered_set<int>::iterator it = ones.find(i);
            for(int j =0; j<ones.size(); j++){
                moves += abs(i - ones[j]);
            }
            ans[i] = moves;
        }
        return ans;
    }
};