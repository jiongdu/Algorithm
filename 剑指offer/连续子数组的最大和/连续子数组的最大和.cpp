/**************************************
* @author dujiong
* @date 2017.2.16
* @version V0.1
**************************************/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==0){
            return 0;
        }
        int maxSum=-65535;
        int tempSum=0;
    	for(int i=0;i<array.size();i++){
            if(tempSum<=0){
                tempSum=array[i];
            }else{
                tempSum+=array[i];
            }
            maxSum=std::max(maxSum, tempSum);
        }
        return maxSum;
    }
};