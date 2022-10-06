class TimeMap {
public:
    unordered_map<string, map<int,string>> mp;
    unordered_map<string, int> prev;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
        prev[key] = max(prev[key],timestamp);
    }
    
    string get(string key, int timestamp) {
        if(prev.find(key) == prev.end()){
            return "";
        }
        if(timestamp>prev[key]){
            return mp[key][prev[key]];
        }else {
            auto it = mp[key].rbegin();
            while(it != mp[key].rend()){
                if(it->first<= timestamp){
                    return mp[key][it->first];
                }
                it++;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */