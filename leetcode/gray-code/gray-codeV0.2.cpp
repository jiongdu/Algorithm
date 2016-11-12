/**************************************
* @author dujiong
* @date 2016.11.12
* @version V0.2
**************************************/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int num = 1<<n;
        for(int i=0;i<num;i++){
            ret.push_back((i>>1)^i);
        }
        return ret;
    }
};