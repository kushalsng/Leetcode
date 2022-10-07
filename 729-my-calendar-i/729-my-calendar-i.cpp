class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(s.empty()){
            s.insert({start,end});
            return true;
        }else{
            for(auto it = s.begin(); it != s.end(); it++){
                
                if(it == s.begin() and next(it,1) == s.end()){
                    if(end<it->first){
                        s.insert({start,end});
                        return true;
                    }
                    if(start >= it->second){
                        s.insert({start,end});
                        return true;
                    }
                }
                else if(it == s.begin()){
                    if(end<=it->first){
                        s.insert({start,end});
                        return true;
                    }
                    if(start >= it->second and end <= (next(it,1))->first){
                        s.insert({start,end});
                        return true;
                    }
                }else if(next(it,1) == s.end()){
                    if(start >= it->second){
                        s.insert({start,end});
                        return true;
                    }
                }else {
                    // cout<<it->first<<" "<<it->second<<", ";
                    if(start >= it->second and end <= (next(it,1))->first){
                        s.insert({start,end});
                        return true;
                    }
                }
            }
            // cout<<endl;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */