/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node*cur, Node* nxt){
        if(!cur)return cur;
        
        if(cur->child){
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
            Node* ptr = solve(cur->next, cur->next->next);
            while(ptr->next)ptr = ptr->next;
            if(nxt){
                // cout<<nxt->val<<" ";
                nxt->prev = ptr;
                ptr->next = nxt;
                // cur = nxt;
            }
        }
        // cout<<cur->val<<" ";
        // if(nxt) cout<<nxt->val<<": ";
        if(cur->next) cur->next = solve(cur->next, cur->next->next);
        return cur;
    }
    Node* flatten(Node* head) {
        if(!head) return head;
        head = solve(head, head->next);
        return head;
    }
};