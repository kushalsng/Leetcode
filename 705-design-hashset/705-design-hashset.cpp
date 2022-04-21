class MyHashSet {
public:
    bool ar[1000001];
    MyHashSet() {
        memset(ar,0,sizeof ar);
    }
    
    void add(int key) {
        if(!ar[key])ar[key]=true;
    }
    
    void remove(int key) {
        if(ar[key])ar[key]=false;
    }
    
    bool contains(int key) {
        return ar[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */