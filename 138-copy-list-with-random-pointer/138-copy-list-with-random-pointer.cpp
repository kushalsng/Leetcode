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
    Node* copyRandomList(Node* head1) {
        if(!head1) return head1;
        Node* head2 = new Node(head1->val);
        Node* t1 = head1->next, *t2 = head2;
        while(t1){
            Node* n = new Node(t1->val);
            t2->next = n;
            t1=t1->next;
            t2 = t2->next;
        }

        t1= head1, t2 = head2;
        int c=0;

        while(t1 && t2){
            c=0;
            Node* t = head1;
            while(t != t1->random){
                c++;
                t = t->next;
            }
            t= head2;
            while(c--) t = t->next;
            t2->random = t;

            t1=t1->next;
            t2 = t2->next;
        }
        return head2;
    }
};