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
        unordered_map<Node*,Node*> mp;
        for(Node* temp = head; temp; temp = temp->next){
            mp[temp] = new Node(temp->val);
        }
        for(Node* temp = head; temp; temp = temp->next){
            Node* clone = mp[temp];
            clone->next = mp[temp->next];
            clone->random = mp[temp->random];
        }
        return mp[head];
    }
};