/**************************************
* @author dujiong
* @date 2016.11.12
* @version V0.1
**************************************/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        for(int i=0;i<n;i++){
            const int high_bit = 1<<i;
            for(int j=ret.size()-1;j>=0;j--){
                ret.push_back(high_bit | ret[j]);
            }
        }
        return ret;
    }
};