/**************************************
* @author dujiong
* @date 2017.2.17
* @version V0.1
**************************************/

class Solution {
public: //假设返回值为 a[l]+a[r] == sum, 则不可能存在 a[l2]+ a[r2]==sum 且 l2<l 或 r2>r,反证法+第二数学归纳，略。
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l=0,r=array.size()-1;
        vector<int> ret;
        while(l<r){
            if((array[l]+array[r])>sum){
                r--;
            } else if((array[l]+array[r])<sum){
                l++;
            } else {
                ret.push_back(array[l]);
                ret.push_back(array[r]);
                return ret;
            }
        }
        return ret;
    }
};