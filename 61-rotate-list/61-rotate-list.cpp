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
        //corner cases
        if(!head) return head;
        if(!head->next) return head;
        
        //n: size of list
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        
        k = k % n;      // if k > n, then k is reduced to k % n.
        
        if(k == 0) return head;     //if k == 0 or n, no rotation required
        
        ListNode* prevHead = head;      //prevHead saves the initial head, to join it will initial tail
        temp = head;
        int ind = 1;
        
        //new head of the list will be on (n - k)th position
        while(temp->next && ind < n - k){
            ind++; 
            temp = temp->next;
        }
        if(temp->next) head = temp->next;
        else return head;
        temp->next = NULL;
        
        temp = head;
        while(temp->next) temp = temp->next;
        
        temp->next = prevHead; 
        
        return head;
    }
};