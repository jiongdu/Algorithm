/**************************************
* @author dujiong
* @date 2016.9.17
* @version V0.1
**************************************/

bool isOk(int n){  return ((n & 1) == 1); }

class Solution{
public:
    void reOrderArray(vector<int> &array){
        std::stable_partition(array.begin(),array.end(),isOk);
    }
};
