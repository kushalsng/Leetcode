class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // cout<<answerKey.size();
        if(k > (answerKey.size() / 2)) return answerKey.size();
        int ctT=0, ctF=0;
        bool allT = true, allF = true;
        for(auto i: answerKey){
            i == 'T' ? ctT++ : ctF++;
            if(allT && i == 'F')allT = false;
            if(allF && i == 'T')allF = false;
        }
        // cout<<"cT = "<<ctT<<", cF = "<<ctF;
        if(allT || allF) return answerKey.size();
        if(ctT < k || ctF < k) return answerKey.size();
        int mx=0, i=0, j=0;
        ctT = 0, ctF = 0;
        while(j<answerKey.size()){
            answerKey[j] == 'T' ? ctT++ : ctF++;
            if(ctT < k || ctF < k) j++;
            else if(ctT == k || ctF == k){
                mx = max(mx, ctT + ctF);
                j++;
            }else if(ctF > k && ctT > k){
                while(ctF > k && ctT > k){
                    answerKey[i] == 'T' ? ctT-- : ctF--;
                    i++;
                }
                if(ctT == k || ctF == k) mx = max(mx, ctT + ctF);
                j++;
            }
        }
        return mx;
    }
};