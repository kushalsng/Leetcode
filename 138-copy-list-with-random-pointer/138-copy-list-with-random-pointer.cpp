/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        for(Node*temp = head; temp ; temp = temp->next->next){
            // Node* nxt = NULL;
            // if(temp->next)nxt=temp->next;
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
        }
        for(Node*temp = head; temp ; temp = temp->next->next){
            temp->next->random = temp->random ? temp->random->next : NULL;
        }
        Node* cloneHead = head->next;
        for(Node*temp = head; temp ; temp = temp->next){
            Node* nxt = temp->next;
            temp->next = temp->next->next;
            if(nxt->next)nxt->next = nxt->next->next;
        }
        return cloneHead;
    }
};