class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(threshold == 0) return arr.size() - k + 1;
        int sum =0;
        for(int i=0; i<k; i++){
            sum += arr[i];
        }
        int avg = sum / k;
        int count;
        avg >= threshold ? count = 1: count = 0;
        
        for(int r=k,l=0; r<arr.size(); l++,r++){
            sum += (arr[r] - arr[l]);
            if(sum/ k >= threshold)count++;
        }
        return count;
    }
};