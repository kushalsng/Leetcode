class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int ind = -1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i] >= arr[i+1]){
                if(arr[i] > arr[i+1]){
                    ind = i; break;
                } else return false;
            }
        }
        if(ind <= 0) return false;
        
        for(int i=ind; i<arr.size()-1; i++){
            if(arr[i] <= arr[i+1]) return false;
        }
        return true;
    }
};