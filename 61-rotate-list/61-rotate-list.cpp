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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(!head->next) return head;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        delete(temp);
        k = k % n;
        if(k == 0) return head;
        
        ListNode* tail = head, *prevHead = head;
        int ind = 1;
        
        while(tail->next && ind< n-k){
            ind++; 
            tail = tail->next;
        }
        
        if(tail->next) head = tail->next;
        else return head;
        
        tail->next = NULL;
        tail = head;
        while(tail->next) tail = tail->next;
        
        tail->next = prevHead;
        return head;
    }
};