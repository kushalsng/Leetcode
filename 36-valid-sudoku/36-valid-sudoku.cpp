class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        unordered_set<int> s;
        for(int i=0;i<9;i++){
            // cout<<"chack, ";

            for(int j=0; j<9; j++){
                if(a[i][j] =='.') continue;
                if(s.find(a[i][j]-'0') != s.end())return false;
                s.insert(a[i][j]-'0');
            }
            s.clear();
        }
        for(int i=0;i<9;i++){

            for(int j=0; j<9; j++){
                if(a[j][i] =='.') continue;
                if(s.find(a[j][i]-'0') != s.end())return false;
                s.insert(a[j][i]-'0');
            }
            s.clear();
        }

        // int i=0,j=0,k =0,l=0;
        for(int k=0;k<=6;k+=3){
            for(int l=0;l<=6;l+=3){
                for(int i=k;i<k+3;i++){
                    for(int j=l; j<l+3; j++){
                        cout<<"chack, ";
                        if(a[i][j] =='.') continue;
                        if(s.find(a[i][j] - '0') != s.end())return false;
                        s.insert(a[i][j]-'0');
                    }
                }
                s.clear();
            }
        }
        return true;
    }
};