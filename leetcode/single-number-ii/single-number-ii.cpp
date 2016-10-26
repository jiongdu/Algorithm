/**************************************
* @author dujiong
* @date 2016.10.26
* @version V0.1
**************************************/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for(int i=0;i<32;i++){
            int d=0;
            int mask = 1<<i;
            for(int j=0;j<n;j++){
                if(A[j]&mask) d++;
                
            }
            if(d%3) ret |= mask;
        }
        return ret;
    }
};