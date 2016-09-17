/**************************************
* @author dujiong
* @date 2016.9.17
* @version V0.1
**************************************/

class Stock {
public:
    int maxProfit(vector<int> prices, int n) {

        if(n==0)
            return 0;
        vector<int> preProfit(n,0);
        vector<int> postProfit(n,0);
        int minPrice = prices[0];
        for(int i=1;i<n;i++){
            minPrice = std::min(minPrice, prices[i]);
            preProfit[i]=std::max(preProfit[i-1],prices[i]-minPrice);
        }

        int maxPrice = prices[n-1];
        for(int j=n-2;j>=0;j--){
            maxPrice = std::max(maxPrice,prices[j]);
            postProfit[j] = std::max(postProfit[j+1],maxPrice-prices[j]);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res = std::max(res, preProfit[i]+postProfit[i]);
        }
        return res;
    }
};
