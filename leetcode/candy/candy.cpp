/**************************************
* @author dujiong
* @date 2016.11.22
* @version V0.1
**************************************/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1]){
                candy[i+1]=candy[i]+1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i] && candy[i-1]<=candy[i]){
                candy[i-1]=candy[i]+1;
            }
        }
        return accumulate(candy.begin(),candy.end(),0);
    }
};