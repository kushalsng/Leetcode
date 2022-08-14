class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> um,flag;
        int n = s.size();
        for(auto c: s)um[c]++, flag[c] = -1;
        for(int i=0; i<n-1;){
            if(i<n-1 && um[s[i]]>1){
                // cout<<s[i]<<" "<<i<<" "<<um[s[i]]<<", ";
                if(flag[s[i]] == 1 || (s[i]>=s[i+1] && flag[s[i+1]] == -1)){
                    um[s[i]]--;
                    s.erase(i,1);
                    if(i>0){
                        i--;
                        if(flag[s[i]] == 1)flag[s[i]]=-1;
                    }
                }else {
                    flag[s[i]] = 1;
                    i++;
                }
                
            }else {
                flag[s[i]] = 1;
                i++;
            }
        }
        return s;
    }
};