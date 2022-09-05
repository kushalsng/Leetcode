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
    void solve(ListNode* &head, ListNode* prev,int &cnt,int n){
        if(!head)return;
        solve(head->next,head,cnt,n);
        if(cnt!=n)cnt++;
        else{
            if(head and prev) prev->next = head->next;
            else if(prev) prev->next = NULL;
            else if(head) head = head->next;
            cnt++;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)return NULL;
        int cnt=1;
        solve(head, NULL,cnt,n);
        return head;
    }
};