class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string,int> mp;
        for(auto s: words)mp[s]++;
        
        int n=s.size(), m= words.size(), l = words[0].size();
        
        for(int i=0; i<=n-m*l; i++){
            int j=i;
            map<string,int> tmp;
            while(j<i+m*l){
                string ss = s.substr(j,l);
                if(mp.find(ss) != mp.end()){
                    tmp[ss]++;
                }else break;
                j+= l;
            }
            bool isValid = true;
            if(mp.size() != tmp.size())isValid = false;
            else{
                auto it1 = mp.begin(), it2 = tmp.begin();
                while(it1 != mp.end() && it2 != tmp.end()){
                    if(it1->first != it2->first || it1->second != it2->second){
                        isValid = false;
                        break;
                    }
                    it1++,it2++;
                }
            }
            if(isValid)
                ans.push_back(i);
        }
        return ans;
    }
};