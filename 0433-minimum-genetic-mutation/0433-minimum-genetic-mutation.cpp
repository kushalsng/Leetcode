class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        set<string> s{bank.begin(), bank.end()};
        
        q.push(start);
        int ans=0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                string c = q.front();
                q.pop();
                if(c == end)return ans;
                s.erase(c);
                for(int j=0;j<8; j++){
                    string t  = c;
                    for(auto ch: "ACGT"){
                        t[j] = ch;
                        if(s.count(t)) q.push(t);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};