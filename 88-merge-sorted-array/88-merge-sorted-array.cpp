class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, size = m;
        int l=0;
        
        while(i<size && j<n && size<= m+n){
            if(nums1[i] < nums2[j]){
                i++;
                continue;
            } else if(nums1[i] == nums2[j]) i++;
            
            l = size -1;
            while( l != i-1){
                nums1[l+1] = nums1[l];
                l--;
            }
            nums1[i] = nums2[j];
            i++;
            j++;
            size++;
        }
        
        if(j<n){
            while(i<m+n && j<n){
                nums1[i] = nums2[j];
                i++;
                j++;
            }
        }
    }
};