class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int>mp;
        for(auto c: num)mp[c]++;
        if(mp.size() == 1 && num[0] == '0') return "0";
        
        char c = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == 1) c = max(c,it->first);
        }
        string ans = "";
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
                if(it->second %2 == 0){
                    if(ans == "" && it->first == '0')continue;
                    else{
                        int fx = it->second/2;
                        while(it->second>fx){
                            ans += it->first;
                            it->second--;
                        }
                    }
                }else{
                    c = max(c,it->first);
                    it->second--;
                    if(ans == "" && it->first == '0')continue;
                    else{
                        int fx = it->second/2;
                        while(it->second>fx){
                            ans += it->first;
                            it->second--;
                        }
                    }
                }
            }
        int ind = ans.size()-1;
        if(c != 0){
            ans += c;
        }
        while(ind>=0){
            ans += ans[ind--];
        }
        return ans;
    }
};