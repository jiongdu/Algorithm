/**************************************
* @author dujiong
* @date 2017.2.17
* @version V0.1
**************************************/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if(sum<3) return ret;
        int small=1;
        int big=2;
        int middle=(1+sum)/2;
        int curSum=small+big;
        vector<int> temp;
        while(small<middle){
            if(curSum==sum){
                temp.clear();
                for(int i=small;i<=big;i++){
                    temp.push_back(i);
                }
                ret.push_back(temp);
            }
            while(curSum>sum && small<middle){
                curSum-=small;
                small++;
                if(curSum==sum){
                    temp.clear();
                	for(int i=small;i<=big;i++){
                    	temp.push_back(i);
                	}
                	ret.push_back(temp);
            	}
            }
            big++;
            curSum+=big;
        }
        return ret;
    }
};