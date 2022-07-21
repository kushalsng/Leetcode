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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* temp = head;
        int c = 1;
        while(c<left){
            temp = temp->next;
            c++;
        }
        int aux = c;
        while(c<=right){
            v.push_back(temp->val);
            temp = temp->next;
            c++;
        }
        temp = head;
        c= 1;
        while(c<left){
            temp = temp->next;
            c++;
        }
        
        while(c<=right){
            temp->val = v[v.size()-1];
            v.pop_back();
            c++;
            temp = temp->next;
        }
        
        return head;
    }
};