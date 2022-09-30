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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        ListNode* ptr = head;
        int u=0,d=m-1,l=0,r=n-1;
        while(u<=d and l<=r and ptr){
            
            for(int col = l;ptr and col<=r; col++){
                mat[u][col] = ptr->val;
                ptr = ptr->next;
            }
            if(++u>d)break;
            
            for(int row=u;ptr and row<=d; row++){
                mat[row][r] = ptr->val;
                ptr = ptr->next;
            }
            if(--r<l)break;
            
            for(int col = r;ptr and col >=l; col--){
                mat[d][col] = ptr->val;
                ptr = ptr->next;
            }
            if(--d<u)break;
            
            for(int row = d;ptr and row>=u; row--){
                mat[row][l] = ptr->val;
                ptr = ptr->next;
            }
            if(++l>r)break;
        }
        return mat;
    }
};