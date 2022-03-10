/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* InsertAtHead(ListNode* head, int val){
        ListNode* n = new ListNode(val);
        if(!head) return n;
        n->next = head;
        return n;
    }
    int getLength(ListNode* head){
        if(!head) return 0;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL, *t1 = l1, *t2 = l2;
        int len1 = getLength(l1), len2 = getLength(l2);
        int aux =0, diff = abs(len1 - len2);
        stack<int> s;
        
        
        while(len1 > len2) {
            s.push(t1->val);
            len1--;
            t1 = t1->next;
        }

        while(len2 > len1) {
            s.push(t2->val);
            len2--;
            t2 = t2->next;
        }
        
        while(t1 && t2){
            s.push(t1->val);
            s.push(t2->val);
            t1 = t1->next;
            t2 = t2->next;
        }
        
        while(!s.empty() && s.size() > diff){
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int sum = op1 + op2 + aux;
            aux = sum/10;
            ans = InsertAtHead(ans, sum % 10);
        }
        while(!s.empty()){
            int sum = aux + s.top();
            s.pop();
            ans = InsertAtHead(ans, sum %10);
            aux = sum /10;
        }
        if(aux != 0) ans = InsertAtHead(ans, aux);
        return ans;
    }
};