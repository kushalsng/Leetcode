class BrowserHistory {
public:
    vector<string> v;
    int pos;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        pos=0;
    }
    
    void visit(string url) {
        while(v.size()> pos+1) v.pop_back();
        v.push_back(url);
        pos++;
    }
    
    string back(int steps) {
        if(steps > pos) steps = pos;
        
        string ans = v[pos - steps];
        pos -= steps;
        return ans;
    }
    
    string forward(int steps) {
        if(pos + steps >= v.size()) steps -= pos + steps - v.size() + 1;
        string ans = v[pos + steps];
        pos += steps;
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */