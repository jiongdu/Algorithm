/**************************************
* @author dujiong
* @date 2016.12.8
* @version V0.1
**************************************/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0 || prices.size()==1){
            return 0;
        }
        int min = prices[0];
        int max = prices[0];
        int maxprofit = 0;
        int temp = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-min > temp){
                temp = prices[i]-min;
                max = prices[i];
            }
            if(max > prices[i]){
                min = prices[i];
                maxprofit += temp;
                temp = 0;
            }
        }
        if(maxprofit == 0){
            return temp;
        }
        if(temp!=0){
            maxprofit+=temp;
        }
        return maxprofit;
    }
};


//同样的道理，每次应该在波谷买入，在波峰卖出
/*
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0 || prices.size()==1){
            return 0;
        }
        int len = prices.size();
        vector<int> change(len, 0);
        int maxprofit = 0;
        for(int i=1;i<len;i++){
            change[i]=prices[i]-prices[i-1];
            if(change[i]>0) maxprofit+=change[i];
        }
        return maxprofit;
    }
};
*/