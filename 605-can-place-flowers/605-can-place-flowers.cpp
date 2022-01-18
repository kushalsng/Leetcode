class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =0;
        if(flowerbed.size()== 1 && flowerbed[0] == 0) count = 1;
        else if(flowerbed.size() == 2){
            if(flowerbed[0] == flowerbed[1] && flowerbed[0] == 0) count = 1;
        } else {
            if(
                flowerbed[0] == 0 &&
                flowerbed[1] == 0
              ) {
                count++;
                flowerbed[0] = 1;
            }
            
            for(int i =1;i<flowerbed.size()-1;i++){
                if(flowerbed[i-1] == 1 || flowerbed[i+1] == 1 || flowerbed[i] == 1) continue;
                else {
                    count++;
                    flowerbed[i] = 1;
                }
            }
            if(
                flowerbed[flowerbed.size() - 1] == 0 &&
                flowerbed[flowerbed.size() - 2] == 0
              ) count++;
        }
        
        return n <= count ? true : false;
    }
};