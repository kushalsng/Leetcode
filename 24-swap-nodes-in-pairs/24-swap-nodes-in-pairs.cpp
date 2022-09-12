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
    int length(ListNode* head){
        int cnt=0;
        ListNode* temp = head;
        while(temp)temp = temp->next, cnt++;
        return cnt;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        int len = length(head);
        // cout<<len;
        ListNode* dumy = new ListNode(0);
        dumy->next = head;
        ListNode* pre = dumy, *cur ,*nxt;
        while(len>=2){
            cur = pre->next;
            nxt = cur->next;
            
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;
            
            len -= 2;
            pre = cur;
        }
        return dumy->next;
    }
};