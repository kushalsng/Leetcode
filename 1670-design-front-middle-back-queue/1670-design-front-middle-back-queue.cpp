class FrontMiddleBackQueue {
public:
    struct Node{
        int val;
        Node* next, *prev;
        Node(int x){
            next = prev = NULL;
            val = x;
        }
    }*head, *tail;

    FrontMiddleBackQueue() {
        head = tail = NULL;
    }
    
    void pushFront(int val) {
        Node* n = new Node(val);
        if(!head){
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }
    
    void pushMiddle(int val) {
        Node* n = new Node(val);
        if(!head) {
            head = tail = n;
            return;
        }
        Node* p=NULL, *s=head, *f=head;
        if(!s->next){
            pushFront(val);
            return;
        }
        while(f && f->next){
            p = s;
            s = s->next;
            f = f->next->next;
        }
        //f ? odd_nodes : even_nodes;
        // if(f)
        n->next = s;
        s->prev = n;
        p->next = n;
        n->prev = p;
    }
    
    void pushBack(int val) {
        Node* n = new Node(val);
        if(!head) {
            head = tail = n;
            return;
        }
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
    
    int popFront() {
        if(!head) return -1;
        int save = head->val;
        if(head == tail){
            head = tail = NULL;
            return save;
        }
        // Node* temp = head;
        head = head->next;
        if(head){
            head->prev->next = NULL;
        head->prev = NULL;
        }
        // delete(temp);
        return save;
    }
    
    int popMiddle() {
        if(!head) return -1;
        int save;
        Node* p=NULL, *s=head, *f=head;
        if(!s->next){
            save = s->val;
            // delete(s);
            head = tail = NULL;
            return save;
        }
        while(f && f->next){
            p = s;
            s = s->next;
            f = f->next->next;
        }
        
        // Node* temp;
        if(f){
            save = s->val;
            s= s->next;
            if(s){
                 s->prev = p;
                p->next = s;
            }
            else return popBack();
        }
        else {
            save = p->val;
            p = p->prev;
            if(p) {
                p->next = s;
                s->prev = p;
            }
            else return popFront();
        }
        return save;
    }
    
    int popBack() {
        if(!head) return -1;
        int save = tail->val;
        // Node* temp = tail;
        if(tail == head){
            head = tail = NULL;
            return save;
        }
        tail = tail->prev;
        if(tail){
            tail->next->prev = NULL;
        tail->next = NULL;
        }
        // delete(temp);
        return save;
    }
};


// ["FrontMiddleBackQueue","pushFront","pushBack","pushMiddle","pushMiddle","popFront","popMiddle","popMiddle","popBack","popFront"]
// [[],[1],[2],[3],[4],[],[],[],[],[]]
/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */