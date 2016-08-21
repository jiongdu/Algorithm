/**************************************
* @author dujiong
* @date 2016.8.21
* @version V0.1
**************************************/

class Solution {
public:
    /**
     * 计算你能获得的最大收益
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {
       vector<int> leftToRight(prices.size(),0);
    	int minLeft = 0;
    	for(int i=1;i<prices.size();i++){       // From left to right
        	if(prices[i]>prices[i-1]){
           	 	leftToRight[i] = std::max(leftToRight[i-1],prices[i]-prices[minLeft]);
       		}
        	else{
            	leftToRight[i] = leftToRight[i-1];
            	if(prices[i]<prices[minLeft]){
                	minLeft = i;
            	}
       	    }
       }

       vector<int> rightToLeft(prices.size(),0);
       int maxRight = prices.size()-1;
       for(int i=prices.size()-2;i>=0;i--){
          if(prices[i]<prices[i+1]){
             rightToLeft[i] = std::max(prices[maxRight]-prices[i],rightToLeft[i+1]);
          }else{
             rightToLeft[i] = rightToLeft[i+1];
             if(prices[i]>prices[maxRight]){
                maxRight = i;
             }
         }
      }

      int ret=0;
      for(int i=0;i<prices.size();i++){
          ret = max(leftToRight[i]+rightToLeft[i],ret);
      }
      return ret;
    }
};
