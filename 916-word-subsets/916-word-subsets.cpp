class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> w2;
        vector<string> ans;
        for(auto s: words2){
            unordered_map<char,int> tmp;
            for(auto c: s){
                tmp[c]++;
                w2[c] = max(w2[c], tmp[c]);
            }
        }
        for(auto s: words1){
            unordered_map<char,int> tmp;
            for(auto c: s){
                tmp[c]++;
            }
            bool isVal = true;
            for(auto it = w2.begin(); it != w2.end(); it++){
                if(it->second > tmp[it->first]){
                    isVal = false;
                    break;
                }
            }
            if(isVal)ans.push_back(s);
        }
        return ans;
    }
};