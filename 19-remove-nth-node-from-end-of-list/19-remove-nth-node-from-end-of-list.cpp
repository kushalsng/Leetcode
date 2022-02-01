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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++; temp = temp->next;
        }
        if(size == n) return head->next;
        int m = size - n;
        
        int ct = 1;
        temp = head;
        while(ct<m) {
            temp = temp->next;
            ct++;
        }
        if(temp->next){
            if(temp->next->next) temp->next = temp->next->next;
            else temp->next = NULL;
        }
        return head;
    }
};