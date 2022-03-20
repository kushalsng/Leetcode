class Solution {
public:
    int helper(vector<int>& t, vector<int>& b, int val, int vit, int vib){
        cout<<t.size()<<endl;
        for(int i=0; i<t.size(); i++){
            if(t[i] == val && b[i] == val) --vit, --vib;
        }
        // cout<<vit<<" "<<vib<<" "<<endl;
        return min(vit,vib);
    }
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int x = t[0], y = b[0];
        bool xvalid = true, yvalid = true;
        int xit=0,xib=0,yit=0,yib=0;
        for(int i=0; i<t.size(); i++){
            if(t[i] != x && b[i] != x && t[i] != y && b[i] != y) return -1;
            if(t[i] == x && xvalid) xit++;
            if(b[i] == x && xvalid) xib++;
            if(t[i] == y && yvalid) yit++;
            if(b[i] == y && yvalid) yib++;
            if(t[i] != x && b[i] != x && xvalid) xvalid = false;
            if(t[i] != y && b[i] != y && yvalid) yvalid = false;

        }
        cout<<xit<<" "<<xib<<" "<<yit<<" "<<yib<<endl;
        if(xit + xib >= t.size() && xvalid)
            return helper(t,b, x, xit, xib);
        else if(yit + yib >= t.size()&& yvalid)
            return helper(t,b,y, yit, yib);
        else return -1;
    }
};