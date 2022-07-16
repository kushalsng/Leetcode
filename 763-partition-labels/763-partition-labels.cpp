class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp, mp2;
        int n = s.size();
        vector<int> ans;
        int rsum=0;
        for(auto c: s) mp[c]++;
        for(int i=0; i<n; i++){
            mp2[s[i]]++;
            if(mp2[s[i]] == mp[s[i]]){
                bool ok = true;
                for(auto it = mp2.begin(); it != mp2.end(); it++){
                    if(it->second != mp[it->first]) ok = false;
                }
                if(ok){
                    ans.push_back(i+1 - rsum);
                    rsum += ans.back();
                }
            }
        }
        return ans;
    }
};