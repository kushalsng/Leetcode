class MapSum {
public:
    map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int ans=0;
        auto it = mp.begin();
        while(it != mp.end() && prefix > it->first) it++;
        while(it != mp.end() && it->first.substr(0,prefix.size()) == prefix){
            ans += it->second;
            it++;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */