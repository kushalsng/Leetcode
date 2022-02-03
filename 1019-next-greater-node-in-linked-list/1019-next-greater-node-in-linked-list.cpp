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
    ListNode* ReverseList(ListNode* curr, ListNode* prev, ListNode* next){
        if(!curr) return prev;
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr) next = curr->next;
        return ReverseList(curr, prev, next);
    }
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
    vector<int> nextLargerNodes(ListNode* head) {
        int size = getSize(head);
        vector<int> ans(size, 0);
        if(!head->next) return ans;
        head = ReverseList(head, NULL, head->next);
        
        stack<int> s;
        ListNode* temp = head;
        int i = size -2;
        while(temp->next && i>=0){
            
            if(temp->val > temp->next->val){
                ans[i] = temp->val;
                s.push(temp->val);
            } else {
                while(!s.empty() && temp->next->val >= s.top()) {
                    s.pop();
                }
                if(!s.empty()) ans[i] = s.top();
            }
            temp = temp->next;
            i--;
        }
        return ans;
    }
};