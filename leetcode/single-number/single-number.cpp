/**************************************
* @author dujiong
* @date 2016.10.26
* @version V0.1
**************************************/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret=0;
        for(int i=0;i<n;i++){
            ret = ret^A[i];
        }
        return ret;
    }
};