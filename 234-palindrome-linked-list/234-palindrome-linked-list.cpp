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
    bool isPalindrome(ListNode* head) {
        int size =0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            size++;
        }
        if(size == 1) return true;
        vector<int>v;
        
        int half = size / 2;
        
        temp = head;
        for(int i =0;i<half;i++){
            v.push_back(temp->val);
            temp = temp->next;
        }
        if(size %2 != 0) temp = temp->next;
        
        bool isPalim = false;
        while(temp){
            if(temp->val == v[v.size()-1]) isPalim = true;
            else{
                isPalim = false;
                break;
            }
            temp = temp->next;
            v.pop_back();
        }
        
        return isPalim;
    }
};