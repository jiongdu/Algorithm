/**************************************
* @author dujiong
* @date 2016.12.7
* @version V0.1
**************************************/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0 || prices.size()==1){
            return 0;
        }
        int maxprofit = 0;
        int min = prices[0];
        for(int i=1;i<prices.size();i++){
            int temp = prices[i]-min;
            if(temp>maxprofit){
                maxprofit=temp;
            }
            if(prices[i]<min){
                min=prices[i];
            }
        }
        return maxprofit;
    }
};