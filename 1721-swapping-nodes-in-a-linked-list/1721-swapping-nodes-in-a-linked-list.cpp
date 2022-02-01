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
    int getSize(ListNode* head){
        if(!head) return 0;
        else if(!head->next) return 1;
        int count =0;
        ListNode* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getSize(head);
        if(n == k && k == 1) return head;
        if(n % 2 !=0 && k - 1 == n/2) return head;
        int near=-1, far = -1;
        
        if(n % 2 == 0){
            if(k<= n/2){
                near = k-1;
                far = n - k;
            } else {
                near = n - k;
                far = k - 1;
            }
        } else {
            if(k - 1 < n/2){
                near = k - 1;
                far = n - k;
            }else {
                near = n - k;
                far = k - 1;
            }
        }
        ListNode* temp = head, *nr = head, *fr = NULL;
        
        int ct = 0;
        while(temp && ct < near){
            temp = temp->next;
            nr = nr->next;
            ct++;
        }
        fr = temp;
        while(temp && ct < far){
            temp = temp->next;
            fr = fr->next;
            ct++;
        }
        int t = nr->val;
        nr->val = fr->val;
        fr->val = t;
        return head;
    }
};