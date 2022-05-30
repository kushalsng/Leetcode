class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> us;
        for(int i=0; i<word.size(); i++){
            int l =0, r= i;
            while(r<word.size()){
                us.insert(word.substr(l, r-l+1));
                l++,r++;
            }
        }
        int ans=0;
        for(auto str: patterns){
            if(us.count(str))ans++;
        }
        return ans;
    }
};