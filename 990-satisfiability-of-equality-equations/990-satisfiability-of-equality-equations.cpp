class Solution {
public:
    bool dfs(char x, char target, vector<string>&eq, set<char>&us, map<char,vector<char>>&mp){
        us.insert(x);
        if(x == target)return true;
        int len = mp[x].size();
        vector<char> vc = mp[x];
        for(int i=0;i<len; i++){
            if(us.find(vc[i]) == us.end()){
                if(dfs(vc[i], target, eq,us,mp))return true;
            }
        }
        us.erase(x);
        return false;
    }
    bool equationsPossible(vector<string>& eq) {
        map<char,vector<char>> mp;
        for(int i=0; i<eq.size(); i++){
            if(eq[i][1] == '='){
                mp[eq[i][0]].push_back(eq[i][3]);
                mp[eq[i][3]].push_back(eq[i][0]);
            }
        }
        set<char> us;
        for(int i=0; i<eq.size(); i++){
            if(eq[i][1] == '!'){
                if(dfs(eq[i][0], eq[i][3], eq,us,mp)){
                    return false;
                }
            }
        }
        return true;
    }
};