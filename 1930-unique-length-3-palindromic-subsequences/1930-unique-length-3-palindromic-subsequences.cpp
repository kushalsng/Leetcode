class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, pair<pair<int,int>, int>> mp;
        int n = s.size();
        for(int i=0; i<n; i++){
            pair p = {1e9,-1e9};
            mp[s[i]] = {p, 0};
        }
        for(int i=0; i<n; i++){
            int f = mp[s[i]].first.first, l =mp[s[i]].first.second;
            mp[s[i]].first.first = min(f,i);
            mp[s[i]].first.second = max(l,i);
        }
        int ans =0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int i=it->second.first.first, j =it->second.first.second;
            set<char> st;
            for(int k = i+1; k<j; k++){
                st.insert(s[k]);
            }
            ans += st.size();
        }
        return ans;
    }
};