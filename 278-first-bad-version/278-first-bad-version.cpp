// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long long bs(long long l, long long r){
        long long mid = (l+r)/2;
        
        if(isBadVersion(mid) && !isBadVersion(mid - 1)) return mid;
        
        isBadVersion(mid) ? mid = bs(l, mid - 1) : mid = bs(mid + 1, r);
        
        return mid;
    }
    
    long long firstBadVersion(int n) {
        if(n==1 && isBadVersion(n)) return n;
        if(n==2){
            if(isBadVersion(n) && !isBadVersion(n-1)) return 2;
            else return 1;
        }
        
        long long l=1, r=n;
        return bs(l,r);
        
    }
};